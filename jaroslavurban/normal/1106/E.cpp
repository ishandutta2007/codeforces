#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

struct seg{
	int s,t,d,w;
};
bool operator<(seg a,seg b){
	if(a.w!=b.w)return a.w>b.w;
	return a.d>b.d;
}
const int N=100010,M=202;
vector<seg>segs;
int nxt[N],n,m,k;
seg bst[N];
ll dp[N][M],inf=2e18;

int find(int idx){return nxt[idx]==idx?idx:nxt[idx]=find(nxt[idx]);}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<k;++i){
		seg s;cin>>s.s>>s.t>>s.d>>s.w;--s.s;--s.t;--s.d;
		segs.push_back(s);
	}
	sort(segs.begin(),segs.end());
	iota(nxt,nxt+N,0);
	for(int i=0;i<n;++i)bst[i]=seg{i,i,i,0};
	for(int i=0;i<k;++i)
		for(int j=find(segs[i].s);j<=segs[i].t;j=find(++j)){
			bst[j]=segs[i];
			nxt[j]=find(segs[i].t+1);
		}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=inf;
	dp[0][0]=0;
	//for(int i=0;i<n;++i)cerr<<bst[i].w<<" ";cerr<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<=m;++j){
			dp[bst[i].d+1][j]=min(dp[bst[i].d+1][j],dp[i][j]+bst[i].w);
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
			if(j<m)dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
		}
//	for(int i=0;i<=n;++i)cerr<<dp[i][1]<<" ";cerr<<endl;
	assert(dp[n][m]!=inf);
	cout<<dp[n][m]<<endl;
}