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

    string s;
    cin >> s;

    vector<vector<bool>> v(s.size(), vector<bool>(2, false));

    int n = s.size();
    s += "+-*/+-*/";
    set<string> total;
    for (int i = n - 2; i >= 5; i--)
    {
        //DBG(i);
        bool a = i + 2 == n || (v[i+2][0] && (s[i] != s[i+2] || s[i+1] != s[i+3]));
        bool b = i + 2 == n || v[i + 2][1];
        if (a || b)
        {
            total.insert(s.substr(i, 2));
            v[i][0] = true;
            //DBG(s.substr(i, 2));
        }

        if (i < n - 2)
        {
            bool c = i + 3 == n || (v[i + 3][1] && (s[i] != s[i+3] || s[i+1] != s[i+4] || s[i+2] != s[i+5]));
            bool d = i + 3 == n || v[i + 3][0];
            if (c || d)
            {
                total.insert(s.substr(i, 3));
                v[i][1] = true;
                //DBG(s.substr(i,3));
            }
        }

        //DBG(v[i]);
    }

    vector<string> a;
    for (auto t : total)
        a.push_back(t);

    sort(ALL(a), [](string s1, string s2)
    {
        int m = min(s1.size(), s2.size());
        for (int i = 0; i < m; i++)
        {
            if (s1[i] < s2[i])
                return true;
            if (s1[i] > s2[i])
                return false;
        }

        if (s1.size() <= s2.size())
            return true;
        return false;
    });

    cout << total.size() << endl;
    for (auto i : a)
        cout << i << endl;
}