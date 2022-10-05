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
ll P,F;
ll CS,CW;
ll S,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>P>>F>>CS>>CW>>S>>W;
		if(S>W) swap(CS,CW), swap(S,W);
		
		ll ma=0;
		FOR(i,CS+1) {
			ll lef=P-i*S;
			if(lef<0) continue;
			ll cw=min(CW,lef/W);
			ll sum=i+cw;
			ll LS=CS-i;
			ll LW=CW-cw;
			
			ll t=F;
			ll s=min(LS,t/S);
			sum+=s;
			t-=s*S;
			ll v=min(LW,t/W);
			sum+=v;
			ma=max(ma,sum);
		}
		cout<<ma<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}