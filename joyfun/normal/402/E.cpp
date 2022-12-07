#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i=a;i<b;i++)

namespace SCC{
    const int N = 2005;
    int dfn[N],low[N],id[N],st[N],_st,_,cc;// _ starts from 0
    void dfs(int c,vi g[]){
        dfn[c]=low[c]=++cc;
        st[_st++]=c;
        for(auto t:g[c])
            if(!dfn[t])
                dfs(t,g),low[c]=min(low[c],low[t]);
            else if(!id[t])
                low[c]=min(low[c],dfn[t]);
        if(low[c]==dfn[c]){
            ++_;
            while(st[--_st]!=c) id[st[_st]]=_;
            id[c]=_;
        }
    }
    vi ng[N];
    int solve(int n,vi g[]){
        fill_n(dfn,n,cc=0);
        fill_n(low,n,_st=0);
        fill_n(id,n,_=0);
        rep(i,0,n) if(!dfn[i]) dfs(i,g);
        rep(i,0,n) --id[i];
        fill_n(ng,_,vi());
        rep(i,0,n) for(auto j:g[i]) if(id[i]!=id[j]) ng[id[i]].pb(id[j]);
        return _;
    }
}

const int N = 2005;
int n;
vi g[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		for (int j = 0; j < n; j++){
			scanf("%d", &x);
			if (x) g[i].pb(j);
		}
	}
	printf("%s\n", SCC::solve(n, g) == 1 ? "YES" : "NO");
	return 0;
}