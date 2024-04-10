#include <bits/stdc++.h>
#define int short
#define fs first
#define sc second
#define mp make_pair
#define vc vector
#define pr pair
#define pb push_back
#define ld long double
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()
#define endl "\n"
#define in cin
#define out cout

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    string s;
    in >> s;
    int n = len(s);
    vc<int> lol(30, 0);
    vc<vc<int>> mom(n + 100, lol);
    vc<vc<vc<int>>> lel(30, mom);
    for (int i = 0; i < n; i++){
        string tek = "";
        for (int d = 1; d < n; d++){
            lel[s[i] - 'a'][d][s[(i + d) % n] - 'a']++;
        }
    }
    ld mem = 0;
    for (auto &v : lel){
        int ans = 0;
        for (auto &d : v){
            int x = 0;
            for (auto &i : d){
                if (i == 1){
                    x++;
                }
            }
            ans = max(ans, x);
        }
        mem += ans;
    }
    ld kek = n;
    out << fixed << setprecision(19) << mem / kek;
}