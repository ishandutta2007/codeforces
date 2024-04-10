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
int N;
int P[202020];
int C[202020];
int vis[202020];

int ok(vector<int>& V,int step) {
	int i,j;
	FOR(i,step) {
		for(j=i;j<V.size();j+=step) if(V[j]!=V[i]) break;
		if(j>=V.size()) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int mi=N;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
		}
		FOR(i,N) {
			cin>>C[i];
			vis[i]=0;
		}
		FOR(i,N) if(vis[i]==0) {
			vector<int> V;
			x=i;
			while(1) {
				vis[x]=1;
				V.push_back(C[x]);
				x=P[x];
				if(x==i) break;
			}
			for(j=1;j*j<=V.size();j++) if(V.size()%j==0) {
				if(ok(V,j)) mi=min(mi,j);
				if(ok(V,V.size()/j)) mi=min(mi,(int)V.size()/j);
			}
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}