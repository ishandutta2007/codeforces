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
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;


    int last_idx = 0;

    int last_A = -1, last_B = -1;
    string substring = "";
    string substring_rev = "";
    vector<pair<int, int>> v;
    FOR(i, t.length())
    {
        substring += t[i];
        substring_rev = t[i] + substring_rev;
        size_t found = s.find(substring);
        size_t found2 = s.find(substring_rev);
        if (found != string::npos) {

            last_A = found + 1;
            last_B = found + substring.length();
        } else if (found2 != string::npos)
        {
            last_A = found2 + substring.length();
            last_B = found2 + 1;
        }
        else
        {
            if (last_A == -1) {
                cout << -1;
                return 0;
            }
            v.push_back(make_pair(last_A, last_B));
            last_A = -1;
            last_B = -1;
            substring = "";
            substring_rev = "";

            i -= 1;
        }


    }

    if (last_A == -1) {
        cout << -1;
        return 0;
    }
    v.push_back(make_pair(last_A, last_B));

    cout << v.size() << endl;
    for (auto p : v) {
        cout << p.first << " " << p.second << endl;

    }
}