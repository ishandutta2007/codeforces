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


int R,N;
int num[101010];
int T[101010],X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>N;
	int ma=-10000000,ret=0;
	num[0]=0;
	for(i=1;i<=N;i++) {
		cin>>T[i]>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		if(i>=1000) ma=max(ma,num[i-1000]);
		num[i]=ma+1;
		
		for(j=max(0,i-1000);j<i;j++) {
			if(T[i]-T[j]>=abs(X[i]-X[j])+abs(Y[i]-Y[j])) num[i]=max(num[i],num[j]+1);
		}
		ret=max(ret,num[i]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}