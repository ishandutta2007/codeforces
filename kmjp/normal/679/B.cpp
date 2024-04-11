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

ll M;
map<ll,pair<ll,ll>> MM;

pair<ll,ll> dfs(ll v) {
	pair<ll,ll> ret={0,0};
	if(MM.count(v)) return MM[v];
	if(v<=7) ret={v,v};
	else {
		ll cu=pow(v,1.0/3);
		while((cu+1)*(cu+1)*(cu+1)<=v) cu++;
		while(cu*cu*cu>v) cu--;
		
		auto rr=dfs(v-cu*cu*cu);
		ret = {rr.first+1,rr.second+cu*cu*cu};
		ret=max(ret,dfs(cu*cu*cu-1));
	}
	return MM[v]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	pair<ll,ll> ret=dfs(M);
	
	cout<<ret.first<<" "<<ret.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}