#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[101010];

ll V[101010];
vector<ll> H[101010],H2[101010];
pair<int,int> ret={-1,-1};
map<ll,int> hashes;

// T.size()+1T.size()hash
vector<ll> tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000009};
	static vector<ll> prim = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	vector<ll> R;
	sort(ALL(T));
	int id=0,i;
	
	ll a=1,b=1;
	R.push_back((a<<32)+b);
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id)%prim.size()])%=momo[0];
		(b+=l*prim[(id+2)%prim.size()])%=momo[1];
		id++;
		R.push_back((a<<32)+b);
	}
	a=b=0;
	for(i=T.size()-1;i>=1;i--) {
		ll h=T[i]>>32, l=T[i]-(h<<32);
		(a+=h*prim[(i-1)%prim.size()])%=momo[0];
		(b+=l*prim[(i+1)%prim.size()])%=momo[1];
		h=R[i-1]>>32, l=R[i-1]-(h<<32);
		a += h;
		b += l;
		R[i-1]=(a<<32)+b;
	}
	
	return R;
}

ll dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) H[cur].push_back(dfs(e,cur));
	V[cur]=tree_normalize(H[cur]).back();
	hashes[V[cur]]++;
	return V[cur];
}

void dfs2(int cur,int pre,ll par) {
	if(--hashes[V[cur]]==0) hashes.erase(V[cur]);
	if(pre!=-1) {
		hashes[par]++;
		H[cur].push_back(par);
	}
	sort(ALL(H[cur]));
	ret=max(ret,{hashes.size(),cur+1});
	
	int i;
	map<ll,ll> M;
	H2[cur]=tree_normalize(H[cur]);
	FOR(i,H[cur].size()) M[H[cur][i]]=H2[cur][i];
	
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,M[V[e]]);
	
	if(pre!=-1 && --hashes[par]==0) hashes.erase(par);
	hashes[V[cur]]++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	dfs2(0,-1,0);
	cout<<ret.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}