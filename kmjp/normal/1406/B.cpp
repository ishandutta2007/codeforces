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
vector<int> V[2];
int Z;
ll ma[6],mi[6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,6) ma[i]=-1LL<<60,mi[i]=1LL<<60;
		ma[0]=mi[0]=1;
		FOR(i,N) {
			cin>>x;
			for(j=4;j>=0;j--) {
				if(ma[j]!=-1LL<<60) {
					ma[j+1]=max(ma[j+1],ma[j]*x);
					mi[j+1]=min(mi[j+1],ma[j]*x);
				}
				if(mi[j]!=1LL<<60) {
					ma[j+1]=max(ma[j+1],mi[j]*x);
					mi[j+1]=min(mi[j+1],mi[j]*x);
				}
			}
		}
		cout<<ma[5]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}