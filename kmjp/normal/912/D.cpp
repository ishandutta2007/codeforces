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

ll N,M,R,K;
int ID[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>R>>K;
	
	ll pat=(N-R+1)*(M-R+1);
	vector<ll> V,W;
	FOR(i,N) {
		x=max(0LL,i-R+1);
		y=min(N-R,(ll)i);
		V.push_back(y-x+1);
	}
	FOR(i,M) {
		x=max(0LL,i-R+1);
		y=min(M-R,(ll)i);
		W.push_back(y-x+1);
	}
	
	sort(ALL(V));
	reverse(ALL(V));
	
	priority_queue<pair<ll,int>> Q;
	FOR(i,M) Q.push({W[i]*V[0],i});
	
	double ret=0;
	while(K--) {
		auto a=Q.top();
		Q.pop();
		ret += a.first;
		x=a.second;
		ID[x]++;
		if(ID[x]<V.size()) Q.push({W[x]*V[ID[x]],x});
	}
	
	_P("%.12lf\n",ret*1.0/pat);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}