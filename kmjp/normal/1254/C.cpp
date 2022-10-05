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
vector<int> V;

ll ask(int T,int I,int J,int K) {
	ll ret;
	cout<<T<<" "<<(I+1)<<" "<<(J+1)<<" "<<(K+1)<<endl;
	cin>>ret;
	return ret;
}
void ans() {
	cout<<0;
	FORR(v,V) cout<<" "<<(v+1);
	cout<<endl;
	exit(0);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int tar=1;
	for(i=2;i<N;i++) {
		ll v=ask(2,0,tar,i);
		if(v<0) tar=i;
	}
	
	V.push_back(0);
	V.push_back(tar);
	vector<pair<ll,int>> C;
	FOR(i,N) if(i!=0 && i!=tar) {
		C.push_back({ask(1,0,tar,i),i});
	}
	sort(ALL(C));
	reverse(ALL(C));
	int t=C[0].second;
	vector<pair<ll,int>> L,R;
	for(i=1;i<C.size();i++) {
		x=ask(2,0,t,C[i].second);
		if(x<0) L.push_back(C[i]);
		else R.push_back(C[i]);
	}
	
	sort(ALL(L));
	sort(ALL(R));
	reverse(ALL(R));
	FORR(v,L) V.push_back(v.second);
	V.push_back(t);
	FORR(v,R) V.push_back(v.second);
	ans();
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}