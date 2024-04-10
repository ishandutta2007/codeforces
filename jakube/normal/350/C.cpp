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

    vector<pair<int, int>> v(n);
    FOR(i, n) cin >> v[i].first >> v[i].second;

    sort(ALL(v), [](pair<int, int> p, pair<int, int> q){
        int a = abs(p.first);
        int b = abs(p.second);
        int c = abs(q.first);
        int d = abs(q.second);
        return pair<int, int>(min(a, b), max(a, b)) < pair<int, int>(min(c, d), max(c, d));
    });

    int count = 0;
    stringstream ss;

    auto f =[&ss, &count](int a, int val, char c, char d)
    {
        if (a)
        {
            ss << "1 " << a << " ";
            if (val > 0)
                ss << c;
            else
                ss << d;
            ss << "\n";
            count++;
        }
    };

    for (auto p : v)
    {
        complex<int> goal(p.first, p.second);
        complex<int> cur(0, 0);

        int a = abs(p.first);
        int b = abs(p.second);

        if (a <= b)
        {
            f(a, p.first, 'R', 'L');
            f(b, p.second, 'U', 'D');
            ss << "2\n";
            f(b, -p.second, 'U', 'D');
            f(a, -p.first, 'R', 'L');
            ss << "3\n";
            count += 2;
        }
        else
        {
            f(b, p.second, 'U', 'D');
            f(a, p.first, 'R', 'L');
            ss << "2\n";
            f(a, -p.first, 'R', 'L');
            f(b, -p.second, 'U', 'D');
            ss << "3\n";
            count += 2;
        }
    }

    cout << count << endl;
    cout << ss.str();
}