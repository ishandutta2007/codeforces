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

int N,K;
ll mo=998244353;

ll from[2020][4];
ll to[2020][4];

int hoge(int a,int b) {
	if(a==b) return 0;
	if(a==0) return 1;
	if(a==3) return 1;
	if(b==0) return 0;
	if(b==3) return 0;
	return 2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	from[1][0]=from[1][3]=1;
	from[2][1]=from[2][2]=1;
	FOR(i,N-1) {
		ZERO(to);
		
		for(j=1;j<=2000;j++) {
			FOR(x,4) FOR(y,4) (to[j+hoge(x,y)][y]+=from[j][x])%=mo;
		}
		
		swap(from,to);
	}
	
	cout<<((from[K][0]+from[K][1]+from[K][2]+from[K][3])%mo)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}