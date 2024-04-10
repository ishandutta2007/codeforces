#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd endl; exit(0)

using namespace std;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

main()
{
#ifdef __linux__

#endif // __linux__
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    bool a[n];
    for (int i = 0; i < n - k + 1; i++)
    {
        string s;
        cin >> s;
        if (s[0] != 'Y')
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    vector<string> sss;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        string s = "";
        s.pb(c);
        sss.pb(s);
    }

    for (char c = 'A'; c <= 'Z'; c++)
    {
        for (char c1 = 'a'; c1 <= 'z'; c1++)
        {
            string gg = "";
            gg.pb(c);
            gg.pb(c1);
            sss.pb(gg);
        }
    }
    vector<string> tek;
    for (int i = 0; i < k - 1; i++){
        tek.pb(sss[i]);
    }
    for (int i = 0; i < n - k + 1; i++){
        if (a[i]){
            tek.pb(sss[i + k]);
        }
        else{
            tek.pb(tek[i]);
        }
    }
    for (auto v : tek){
        cout << v << ' ';
    }
}