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


int Q;
int num;
multiset<int> S[32];
ll sum[32];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&Q);
	while(Q--) {
		char C[10];
		scanf("%s%d",&C,&x);
		y=0;
		while(x>=(1<<(y+1))) y++;
		
		if(C[0]=='+') {
			S[y].insert(x);
			sum[y]+=x;
			num++;
		}
		else {
			S[y].erase(S[y].find(x));
			sum[y]-=x;
			num--;
		}
		
		int ret=num;
		ll tot=0;
		FOR(i,31) if(S[i].size()) {
			if(2*tot<*S[i].begin()) ret--;
			tot+=sum[i];
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}