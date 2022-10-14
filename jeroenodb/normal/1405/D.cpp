#include <iostream>
#include <string>
#include <vector>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';
const int mxN = 1e5+3;
int n,a,b,da,db,d[mxN];
vector<int> adj[mxN];

int dfs(int at, int from=0,int md=0) {
    int ans = at;
    d[at]=md;
    for(int to:adj[at]) {
        if(to==from) continue;
        int cur = dfs(to,at,md+1);
        if(d[cur]>d[ans]) ans=cur;
    }
    return ans;
}

diam() {
    int root = dfs(1);
    int farthest = dfs(root);
    return d[farthest];
}

void solve() {

    cin >> n >> a >> b >> da >> db;
    for(int i=1;i<=n;++i) adj[i].clear();
    for (int i = 0; i < n-1; i++)
    {
       int u,v; cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
       
    }
    if(da*2>=db) {
        cout << "Alice\n"; return;
    }
    int diameter=diam();
    //D(diameter);D(da);
    if(diameter<=da*2) {
        cout << "Alice\n"; 
    } else {
        dfs(a);
        if(d[b]<=da) cout << "Alice\n"; 
        else cout << "Bob\n";
    }
    

}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}