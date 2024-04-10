#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n+1);
    FOR(i, n+1) cin >> v[i].first >> v[i].second;

    int start = 0;
    FOR(i, n+1)
    {
        if (v[i].second < v[start].second)
            start = i;
        else if (v[i].second == v[start].second && v[i].first < v[start].first)
            start = i;
    }

    //for (auto i : v)
    //    DBG(i);

    pair<double, double> u(v[start].first + 0.5, v[start].second + 0.5);

    double total = 0;
    FOR(i, n)
    {
        int p = (start + i) % (n);
        int q = (start + i + 1) % (n);

        pair<double, double> vec1(v[p].first - u.first, v[p].second - u.second);
        pair<double, double> vec2(v[q].first - u.first, v[q].second - u.second);

        double tmp = atan2(vec2.second, vec2.first) - atan2(vec1.second, vec1.first);
        //cout << p << ", " << q << ": " << tmp << endl;
        if (tmp < PI)
            tmp += 2*PI;
        if (tmp >= PI)
            tmp -= 2*PI;
        total += tmp;
    }

    //DBG(total);
    //bool clockwise = (total > -1) && (total < 1);
    //cout << (clockwise ? "true" : "false") << endl;

    int cnt = 0;
    FOR(i, n)
    {
        int p = (start + i) % (n);
        int q = (start + i + 1) % (n);
        int r = (start + i + 2) % (n);

        pair<double, double> vec1(v[p].first - v[q].first, v[p].second - v[q].second);
        pair<double, double> vec2(v[r].first - v[q].first, v[r].second - v[q].second);

        double tmp = atan2(vec2.second, vec2.first) - atan2(vec1.second, vec1.first);
        if (tmp < PI)
            tmp += 2*PI;
        if (tmp >= PI)
            tmp -= 2*PI;
        //DBG(tmp);

        if ((tmp < 0)) {
                cnt++;
                //cout << p << " " << q << " " << r << endl;

        }
    }
    cout << cnt;
}