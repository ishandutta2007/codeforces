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

int N,M,T;
int A[2020];
int O[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,2*N) cin>>A[i+1];
	FOR(i,M) {
		cin>>x>>y;
		O[x]=y;
		O[y]=x;
	}
	cin>>T;
	int F=T;
	FOR(j,N) {
		if(T==2) {
			cin>>x;
			A[x]=-1;
			if(O[x]&&A[O[x]]>=1) {
				cout<<O[x]<<endl;
				A[O[x]]=-1;
				continue;
			}
			T=1;
		}
		
		vector<pair<int,int>> V;
		
		for(i=1;i<=2*N;i++) if(A[i]>0) {
			if(O[i]==0) {
				V.push_back({A[i],i});
			}
			else if(A[i]>A[O[i]] || (A[i]==A[O[i]] && i<O[i])) {
				break;
			}
		}
		
		
		if(i<=2*N) {
			cout<<i<<endl;
			A[i]=-1;
		}
		else {
			assert(V.size());
			sort(ALL(V));
			reverse(ALL(V));
			cout<<V[0].second<<endl;
			A[V[0].second]=-1;
			
		}
		T=2;
	}
	
	if(F==1) {
		cin>>x;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}