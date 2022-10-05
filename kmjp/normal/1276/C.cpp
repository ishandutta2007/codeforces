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
map<int,int> C;
vector<int> D[404040];
int sum[404040];
 
vector<int> ret[404040];
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C[x]++;
	}
	
	ll S=N;
	int over=0;
	FORR(m,C) D[m.second].push_back(m.first);
	
	int H=0,W=0,ma=0;
	for(i=400000;i>=1;i--) {
		
		ll sum=S+over*i;
		int tw=sum/i;
		if(tw>=i) {
			if(i*tw>ma) {
				ma=i*tw;
				H=i;
				W=tw;
			}
		}
		
		S-=D[i].size()*i;
		over+=D[i].size();
	}
	
	int num=0;
	for(i=400000;i>=1;i--) {
		FORR(d,D[i]) {
			FOR(j,min(H,i)) if(num<ma) {
				ret[num%H].push_back(d);
				num++;
			}
		}
	}
	
	cout<<ma<<endl;
	cout<<H<<" "<<W<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<ret[y][(x-y+W)%W]<<" ";
		cout<<endl;
	}
	
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}