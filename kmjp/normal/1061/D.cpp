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
ll X,Y;
int L[101010],R[101010];
ll mo=1000000007;
multiset<ll> M;
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	ll ret=0;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		V.push_back({R[i],L[i]});
	}
	
	sort(ALL(V));
	reverse(ALL(V));
	FORR(v,V) {
		ll R=v.first;
		ll L=v.second;
		auto it=M.lower_bound(R+1);
		
		if(it!=M.end() && (*it-L)*Y<X+(R-L)*Y) {
			(ret+=(*it-L)*Y)%=mo;
			M.erase(it);
		}
		else {
			(ret+=X+(R-L)*Y)%=mo;
		}
		M.insert(L);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}