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

    string s;
    cin >> s;
    lint a, b;
    cin >> a >> b;


    lint n = 0;
    lint m = 0;
    lint t = 1;
    set<int> se;

    FOR(i, s.size()-1) {
        n = (10 * n + s[i] - '0') % a;
        if (n == 0) {
            se.insert(i + 1);
        }
    }

    FOR(i, s.size()-1) {
        m = (m + t * (s[s.size() - 1 - i] - '0')) % b;
        if (m == 0 && s[s.size() - 1 - i] != '0' && se.count(s.size() - 1 - i)) {
            cout << "YES" << endl << s.substr(0, (s.size() - 1 - i) ) << endl << s.substr((s.size() - 1 - i)) << endl;
            return 0;
        }
        t = (t*10) % b;
    }

    cout << "NO" << endl;
}