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

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    FOR(i, n) cin >> v[i];

    map<int, int> map, map2;
    int ma = 0;
    vector<pair<int,int>> vp(m);

    FOR(i, m) {
        int first, order;
        cin >> order >> first;
        vp[i] = make_pair(first, order);
    }

    FOR(i, m)
    {
        int first = vp[m-i-1].first;
        int order = vp[m-i-1].second;
        if (first > ma)
        {
            map[first] = order;
            ma = max(ma, first);
        }
    }

    vector<int> reversed_output;
    for (int i = n-1; i > ma-1; i--)
    {
        reversed_output.push_back(v[i]);
        v.pop_back();
    }

    sort(ALL(v));

    deque<int> dq;
    FOR(i, ma)
        dq.push_back(v[i]);

    int last = 0;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        map2[last] = it->second;
        last = it->first;
    }

    for (auto it = map2.rbegin(); it != map2.rend(); ++it) {
        int first = it->first;
        int order = it->second;

        while (first < ma) {
            if (order == 2) {
                reversed_output.push_back(dq.front());
                dq.pop_front();
            }
            else {
                reversed_output.push_back(dq.back());
                dq.pop_back();
            }
            ma--;
        }
    }

    FOR(i, n)
        cout << reversed_output[n-i-1] << " ";
}