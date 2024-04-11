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

int N,Q;
int to[36];
ll num[8][1000000];
int f6[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(to);
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>s;
		x=(s[0]-'a')*6+(s[1]-'a');
		cin>>s;
		to[x]=s[0]-'a';
	}
	
	f6[0]=1;
	FOR(i,7) f6[i+1]=f6[i]*6;
	
	num[1][0]=1;
	ll tot=0;
	for(i=2;i<=N;i++) {
		tot=0;
		FOR(x,f6[i]) {
			j=i-2;
			y=x/f6[j]%36;
			if(to[y]>=0) {
				y = x/f6[j+2]*f6[j+1]+to[y]*f6[j]+x%f6[j];
				num[i][x] += num[i-1][y];
			}
			if(num[i][x]) tot++;
		}
	}
	cout<<tot<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}