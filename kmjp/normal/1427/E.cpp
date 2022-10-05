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

vector<vector<ll>> X;
set<ll> S;

vector<ll> add(vector<ll> T,ll v) {
	S.insert(v);
	FORR(t,T) {
		if((t^v)<v) {
			if(S.count(t^v)==0) {
				X.push_back({t,v,1});
				S.insert(t^v);
			}
			v^=t;
		}
	}
	if(v) {
		ll msb=1;
		while(msb<<1 <= v) msb<<=1;
		FORR(t,T) if(t&msb) {
			if(S.count(t^v)==0) {
				X.push_back({t,v,1});
				S.insert(t^v);
			}
			t^=v;
		}
		T.push_back(v);
		sort(ALL(T));reverse(ALL(T));
	}
	return T;
}

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	vector<ll> V;
	
	while(S.count(1)==0) {
		for(i=1;i<=100;i++) {
			V.push_back(N*i);
			if(i>1 && S.count(N*i)==0) X.push_back({N*(i-1),N,0});
			S.insert(N*i);
		}
		if((N&(N+1))==0) {
			V.push_back(N^(2*N));
			S.insert(N^(2*N));
			X.push_back({N,2*N,1});
			N+=2;
			continue;
		}
		for(i=1;i<=20;i++) {
			V.push_back(N<<(i-1));
			if(i>1 && S.count(N<<(i-1))==0) X.push_back({N<<(i-2),N<<(i-2),0});
			S.insert(N<<(i-1));
			V.push_back(N+(N<<(i-1)));
			S.insert(N+(N<<(i-1)));
			X.push_back({N<<(i-1),N,0});
		}
		vector<ll> T;
		sort(ALL(V));
		reverse(ALL(V));
		FORR(v,V) T=add(T,v);
		V=T;
		sort(ALL(V));
		if(count(ALL(V),1)) {
			break;
		}
		if(S.count(N+V[0])==0) {
			X.push_back({N,V[0],0LL});
			S.insert(N+V[0]);
		}
		N+=V[0];
		while(N%2==0) {
			if(S.count(N+V[0])==0) {
				X.push_back({N,V[0],0LL});
				S.insert(N+V[0]);
			}
			N+=V[0];
		}
		
		
	}
	//return;
	assert(S.count(1));
	cout<<X.size()<<endl;
	FORR(a,X) {
		if(a[2]==0) cout<<a[0]<<" + "<<a[1]<<endl;
		if(a[2]==1) cout<<a[0]<<" ^ "<<a[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); 
	/*
	for(int i=3;i<=999999;i+=2) {
		S.clear();
		X.clear();
		
		N=i;
		solve();
	}
	*/
	solve();
	return 0;
}