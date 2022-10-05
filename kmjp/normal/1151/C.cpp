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

vector<pair<ll,ll>> V;
ll L,R;
ll mo=1000000007;
ll hoge(ll v) {
	ll ret=0;
	FORR(r,V) {
		ll m=min(r.second,v);
		(ret+=(r.first+r.first+2*(m-1))%mo*(m%mo))%=mo;
		v-=m;
	}
	
	return ret*(mo+1)/2%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll cur[2]={1,2};
	int step=0;
	for(ll num=1;num<1LL<<61;num<<=1) {
		V.push_back({cur[step]%mo,num});
		(cur[step] += num*2)%=mo;
		step^=1;
	}
	cin>>L>>R;
	cout<<(hoge(R)-hoge(L-1)+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}