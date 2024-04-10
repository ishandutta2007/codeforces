#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
int A[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int sum=0;
		FOR(i,N) {
			cin>>A[i+1];
			sum+=A[i+1];
		}
		if(sum%N) {
			cout<<-1<<endl;
			continue;
		}
		sum/=N;
		vector<vector<int>> V;
		int up=1;
		while(up) {
			up=0;
			for(i=2;i<=N;i++) if(A[i]) {
				int lef=(i-A[i]%i)%i;
				
				if(lef==0) {
					V.push_back({i,1,A[i]/i});
					A[1]+=A[i];
					A[i]=0;
					up=1;
				}
				else if(A[1]>=lef) {
					V.push_back({1,i,lef});
					A[1]-=lef;
					A[i]+=lef;
					V.push_back({i,1,A[i]/i});
					A[1]+=A[i];
					A[i]=0;
					up=1;
				}
			}
			if(up==0) {
				int ma=2,v=0;
				for(i=2;i<=N;i++) if(A[i]/i*i>v) ma=i,v=A[i]/i*i;
				if(v>0) {
					V.push_back({i,1,A[ma]/ma});
					A[1]+=A[ma]/ma;
					A[i]-=A[ma]/ma;
					
				}
			}
		}
		assert(A[1]==sum*N);
		for(i=2;i<=N;i++) {
			assert(A[i]==0);
			V.push_back({1,i,sum});
		}
		
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}