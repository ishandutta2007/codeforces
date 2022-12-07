#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

const int N = 100001;

vector<pair<int, int>> adj[N];
int lcaNode, path;
bool flag;
int dfsCheck(int i, int par, int dist) {
    int maxDist = 0;
    int cnt = 0;
    for(const auto& cur : adj[i]) {
        int j = cur.first;
        int weight = cur.second;
        if(j != par) {
            int curDist = dfsCheck(j, i, dist);
            if(curDist + weight > dist) {
                cnt++;
                path++;
            }
            maxDist = max(maxDist, curDist + weight);
        }
    }
    if(i != lcaNode && cnt >= 2) 
        flag = false;
    if(i == lcaNode && cnt >= 3)
        flag = false;
    return maxDist;
}
int dfsFindLca(int i, int par, int dist) {
    int maxDist = 0;
    for(const auto& cur : adj[i]) {
        int j = cur.first;
        int weight = cur.second;
        if(j != par) {
            int curDist = dfsFindLca(j, i, dist);
            if(curDist + weight > dist && lcaNode == 0) {
                lcaNode = j;
            }
            maxDist = max(maxDist, curDist + weight);
        }
    }
    return maxDist;
}
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
    
    int n;
    cin >> n;

    int k;
    cin >> k;

    for(int i = 0; i < n - 1; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--;
        v--;
        adj[u].pb(mp(v, weight));
        adj[v].pb(mp(u, weight));
    }

    int start = 0, end = (int)1e9, ans = (int)1e9;

    while(start <= end) {
        int mid = (start + end) >> 1;

        lcaNode = 0;
        dfsFindLca(0, -1, mid);

        flag = true;
        path = 1;
        dfsCheck(lcaNode, -1, mid);

        if(flag && path <= k) {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    cout << ans;

    return 0;
}