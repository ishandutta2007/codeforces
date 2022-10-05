#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int A,B,M,Q;
deque<int> D[404040];
int U[404040],V[404040];
pair<int,int> E[404040]; //index
int col[404040];
ll p2[404040];
const ll mo=998244353;

ll ret=0;

void add(int i,int x,int y) {
	y+=200000;
	U[i]=x;
	V[i]=y;
	int k,r;
	if(E[x].first==y) {
		//connect
		k=E[x].second;
		col[i]=col[D[k][0]]^1;
		if(col[i]==1) ret+=p2[i];
		E[x]=E[y]={0,0};
	}
	else if(E[x].first&&E[y].first) {
		int ox=E[x].first;
		int oy=E[y].first;
		k=E[x].second;
		r=E[y].second;
		
		assert(U[k]==x||V[k]==x);
		assert(U[r]==y||V[r]==y);
		
		if(D[k].size()<=D[r].size()) {
			swap(k,r);
			swap(x,y);
			swap(ox,oy);
		}
		
		if(U[r]!=y) reverse(ALL(D[r]));
		
		if(U[k]==x) {
			int cur=col[D[k][0]];
			D[k].push_front(i);
			cur^=1;
			col[i]=cur;
			if(col[i]) ret+=p2[i];
			
			FORR(v,D[r]) {
				if(col[v]) ret-=p2[v];
				cur^=1;
				col[v]=cur;
				if(col[v]) ret+=p2[v];
				D[k].push_front(v);
			}
			U[k]=oy;
		}
		else {
			int cur=col[D[k].back()];
			D[k].push_back(i);
			cur^=1;
			col[i]=cur;
			if(col[i]) ret+=p2[i];
			
			FORR(v,D[r]) {
				if(col[v]) ret-=p2[v];
				cur^=1;
				col[v]=cur;
				if(col[v]) ret+=p2[v];
				D[k].push_back(v);
			}
			V[k]=oy;
		}
		E[x]=E[y]={0,0};
		E[ox]={oy,k};
		E[oy]={ox,k};
		assert((U[k]==ox&&V[k]==oy)||(U[k]==oy&&V[k]==ox));
		D[r].clear();
		
	}
	else if(E[x].first||E[y].first) {
		if(E[y].first) swap(x,y);
		int o=E[x].first;
		k=E[x].second;
		assert(U[k]==x||V[k]==x);
		if(U[k]==x) {
			r=D[k][0];
			col[i]=col[r]^1;
			if(col[i]) ret+=p2[i];
			D[k].push_front(i);
			U[k]=y;
			assert(V[k]==o);
		}
		else {
			r=D[k].back();
			col[i]=col[r]^1;
			if(col[i]) ret+=p2[i];
			D[k].push_back(i);
			V[k]=y;
			assert(U[k]==o);
		}
		E[o]={y,k};
		E[x]={0,0};
		E[y]={o,k};
	}
	else {
		D[i].push_back(i);
		E[x]={y,i};
		E[y]={x,i};
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,401010) {
		p2[i+1]=p2[i]*2%mo;
	}
	
	cin>>A>>B>>M;
	for(i=1;i<=M;i++) {
		cin>>x>>y;
		add(i,x,y);
	}
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			M++;
			add(M,x,y);
			ret=(ret%mo+mo)%mo;
			cout<<ret<<endl;
		}
		else {
			int c=0;
			for(i=1;i<=M;i++) c+=col[i];
			cout<<c;
			for(i=1;i<=M;i++) if(col[i]) cout<<" "<<i;
			cout<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}