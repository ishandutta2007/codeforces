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
string S;

vector<ll> Us,Ds;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	Us.push_back(0);
	Ds.push_back(0);
	FOR(i,N) {
		if(S[i]=='U') Us.push_back(Us.back()+i);
		if(S[i]=='D') Ds.push_back(Ds.back()+i);
	}
	int NU=0,ND=Ds.size()-1;
	x=y=0;
	FOR(i,N) {
		if(S[i]=='D') y++;
		int y2=Ds.size()-1-y;
		ll ret;
		if(S[i]=='U') {
			if(y2<=x) {
				ret = 2*((Ds.back()-Ds[y])-1LL*y2*i)+N-i;
				ret += 2*(1LL*i*y2-(Us[x]-Us[x-y2]));
			}
			else {
				ret = 2*((Ds[y+x+1]-Ds[y])-1LL*(x+1)*i);
				ret += 2*(1LL*i*x-Us[x])+i+1;
			}
			x++;
		}
		else {
			ret=-1;
			if(x>y2) {
				ret = 2*((Ds.back()-Ds[y])-1LL*y2*i)+N-i;
				ret += 2*(1LL*i*(y2+1)-(Us[x]-Us[x-(y2+1)]));
			}
			else {
				ret = 2*((Ds[y+x]-Ds[y])-1LL*(x)*i);
				ret += 2*(1LL*i*x-Us[x])+i+1;
			}
			
		}
		
		_P("%I64d ",ret);
	}
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}