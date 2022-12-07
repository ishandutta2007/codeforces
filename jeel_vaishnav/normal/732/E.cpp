#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n, m;
    cin >> n >> m;

    int p[n];
    int s[m];

    for(int i = 0; i < n; ++i)
        cin >> p[i];

    for(int i = 0; i < m; ++i)
        cin >> s[i];

    int ans = 0;

    int vis[n];
    for(int i = 0; i < n; ++i)
        vis[i] = 0;

    int viss[m];
    for(int i = 0; i < m; ++i)
        viss[i] = 0;

    int pluggedSocket[n];
    for(int i = 0; i < n; ++i)
        pluggedSocket[i] = -1;

    int pluggedAdapters[m];
    for(int i = 0; i < m; ++i)
        pluggedAdapters[i] = 0;

    for(int l = 0; l <= 31; ++l) {
        unordered_map<int, vector<int>> smap;
        for(int j = 0; j < m; ++j) {
            if(viss[j] == 0) {
                if(smap.find(s[j]) == smap.end()) {
                    vector<int> curv;
                    smap[s[j]] = curv;
                }
                smap[s[j]].pb(j);
            }
        }

        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                if(smap.find(p[i]) != smap.end()) {
                    if(smap[p[i]].size() != 0) {
                        int lastInd = smap[p[i]].size() - 1;
                        int curSocket = smap[p[i]].back();
                        smap[p[i]].pop_back();

                        viss[curSocket] = 1;
                        ans += l;
                        vis[i] = 1;
                        pluggedSocket[i] = curSocket;
                        pluggedAdapters[curSocket] = l;
                    }
                }
            }
        }

        for(int j = 0; j < m; ++j) 
            s[j] = (s[j] - 1) / 2 + 1;
    }

    int totalComp = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i] == 1)
            totalComp++;
    }

    cout << totalComp << " " << ans << "\n";
    for(int i : pluggedAdapters)
        cout << i << " ";
    cout << "\n";
    for(int i : pluggedSocket)
        cout << (i + 1) << " ";


    return 0;
}