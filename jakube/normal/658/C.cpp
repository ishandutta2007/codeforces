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

    int n, d, h;
    cin >> n >> d >> h;

    if (d + 1 > n || d > 2*h || d < h || h + 1 > n || (d == 1 && h == 1 && n > 2))
    {
        cout << -1;
        return 0;
    }

    int cur = 1;
    n--;

    FOR(i, h) {
        cout << cur << " " << cur + 1 << endl;
        cur++;
        n--;
        d--;
    }

    int level = 1;
    while (n > 0)
    {
        if (d)
        {
            while (n > 0)
            {
                int cur2 = level;
                FOR(i, d)
                {
                    cout << cur2 << " " << cur + 1 << endl;
                    cur++;
                    cur2 = cur;
                    n--;
                    if (n == 0)
                        return 0;
                }
            }
        }
        else {
            d++;
            level++;
        }
    }
}