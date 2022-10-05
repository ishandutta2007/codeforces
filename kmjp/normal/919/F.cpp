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

int T;
map<vector<int>,int> MP;
vector<vector<int>> C;
vector<int> pre[2020][2020];
int ret[2020][2020];
int lef[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<int> V(5),W(5);
	
	
	int cnt=0;
	FOR(V[0],9) FOR(V[1],9) FOR(V[2],9) FOR(V[3],9) FOR(V[4],9) {
		if(V[0]+V[1]+V[2]+V[3]+V[4]==8) {
			MP[V]=cnt++;
			C.push_back(V);
		}
	}
	FOR(x,cnt) FOR(y,cnt) {
		V=C[x];
		W=C[y];
		for(i=1;i<=4;i++) if(V[i]) {
			V[i]--;
			for(j=1;j<=4;j++) if(W[j]) {
				V[(i+j)%5]++;
				pre[y][MP[V]].push_back(x);
				lef[x][y]++;
				V[(i+j)%5]--;
			}
			V[i]++;
		}
	}
	MINUS(ret);
	
	queue<int> Q;
	FOR(x,cnt-1) {
		ret[x][cnt-1]=0;
		Q.push(x*10000+cnt-1);
	}
	
	while(Q.size()) {
		x=Q.front()/10000;
		y=Q.front()%10000;
		Q.pop();
		
		/*
		FORR(v,C[x]) cout<<v;
		cout<<" ";
		FORR(v,C[y]) cout<<v;
		cout<<"  "<<ret[x][y]<<endl;
		*/
		if(ret[x][y]==1) {
			FORR(e,pre[x][y]) if(ret[e][x]==-1) {
				if(--lef[e][x]==0) {
					ret[e][x]=0;
					Q.push(e*10000+x);
				}
			}
		}
		else {
			FORR(e,pre[x][y]) if(ret[e][x]==-1) {
				ret[e][x]=1;
				Q.push(e*10000+x);
			}
		}
	}
	
	scanf("%d",&T);
	while(T--) {
		int first;
		
		int A[8],B[8];
		int AV=0,BV=0;
		scanf("%d",&first);
		scanf("%d%d%d%d%d%d%d%d",&A[0],&A[1],&A[2],&A[3],&A[4],&A[5],&A[6],&A[7]);
		scanf("%d%d%d%d%d%d%d%d",&B[0],&B[1],&B[2],&B[3],&B[4],&B[5],&B[6],&B[7]);
		V.resize(0);
		W.resize(0);
		V.resize(5);
		W.resize(5);
		FOR(i,8) V[A[i]]++, W[B[i]]++;
		/*
		FORR(v,V) cout<<v;
		cout<<" ";
		FORR(v,W) cout<<v;
		cout<<endl;
		*/
		if(first==0) {
			x=ret[MP[V]][MP[W]];
			if(x==1) _P("Alice\n");
			else if(x==0) _P("Bob\n");
			else _P("Deal\n");
		}
		else {
			x=ret[MP[W]][MP[V]];
			if(x==1) _P("Bob\n");
			else if(x==0) _P("Alice\n");
			else _P("Deal\n");
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}