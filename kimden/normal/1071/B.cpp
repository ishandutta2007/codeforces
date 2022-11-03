#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
   // srand(413);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        //s[i] = string(n, 'z');
    }
    const int INF = 1000000000;
    vector<vector<int>> v(n, vector<int>(n));
    v[0][0] = (s[0][0] == 'a' ? 0 : 1);
    for(int i = 1; i < n + n - 1; ++i){
        for(int j = max(0, i - n + 1); j < n && j <= i; ++j){
            v[j][i - j] = (s[j][i - j] == 'a' ? 0 : 1) + min((j > 0 ? v[j - 1][i - j] : INF), (i - j > 0 ? v[j][i - j - 1] : INF));
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(v[i][j] <= k){
                s[i][j] = 'a';
            }
        }
    }
 /*   for(int i = 0; i < n; ++i){
        cerr << s[i] << endl;
        //s[i] = string(n, 'z');
    }*/
    vector<pii> q[2];
    int cur = 0;
    string ans = "";
    ans.push_back(s[0][0]);
    q[cur].push_back({0, 0});
    q[1 - cur].clear();
    while(1){
        char mn = char((int)'z' + 1);
        for(auto x: q[cur]){
            int u = x.first;
            int v = x.second;
            if(u != n - 1){
                mn = min(mn, s[u + 1][v]);
            }
            if(v != n - 1){
                mn = min(mn, s[u][v + 1]);
            }
        }
        if(mn == char((int)'z' + 1)){
            break;
        }
        ans.push_back(mn);
        bool yes = false;
        for(int i = 0; i < q[cur].size(); ++i){
            int u = q[cur][i].first;
            int v = q[cur][i].second;
            if(u != n - 1 && s[u + 1][v] == mn){
                if(!yes){
                    q[1 - cur].push_back({u + 1, v});
                }
            }
            yes = false;
            if(v != n - 1 && s[u][v + 1] == mn){
                q[1 - cur].push_back({u, v + 1});
                yes = true;
            }
            if(!(i != q[cur].size() - 1 && q[cur][i].first == q[cur][i + 1].first + 1)){
                yes = false;
            }
        }
        cur = 1 - cur;
        q[1 - cur].clear();
    }
    cout << ans << endl;





}