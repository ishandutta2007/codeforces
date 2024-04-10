#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define int long long

typedef long long ll;

using namespace std;

void solve();
signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout.precision(15); cout << fixed;
    solve();
    return 0;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char, int> > f;
    for(int i = 0; i < n; i ++){
        if(f.empty() || f.back().first != s[i]) f.push_back({s[i], 1});
        else f.back().second++;
    }
    for(char c = 'z'; c >= 'a'; c--){
        vector<pair<char, int> > nf;
        for(int i = 0; i < f.size(); i++){
            if(f[i].first != c){
                if(nf.empty() || nf.back().first != f[i].first) nf.push_back(f[i]);
                else nf.back().second += f[i].second;
            } else{
                if(i && (int)f[i - 1].first == (int)(c - 1)) continue;
                else if(i < (n - 1) && (int)(f[i + 1].first) == (int)(c - 1)) continue;
                else{
                    if(nf.empty() || nf.back().first != f[i].first) nf.push_back(f[i]);
                    else nf.back().second += f[i].second;
                }
            }
        }
        f = nf;
    }
    int ans = 0;
    for(int i = 0; i < f.size(); i++)
        ans += f[i].second;
    cout << n - ans << endl;
}