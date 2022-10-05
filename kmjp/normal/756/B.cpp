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
int T[101010];
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>T[i];
		ret[i]=1LL<<60;
	}
	for(i=1;i<=N;i++) {
		ret[i]=min(ret[i],ret[i-1]+20);
		for(j=i+1;j<=N && T[j]-T[i]<90;j++) ret[j]=min(ret[j],ret[i-1]+50);
		for(j=i+1;j<=N && T[j]-T[i]<1440;j++) ret[j]=min(ret[j],ret[i-1]+120);
		cout<<ret[i]-ret[i-1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}