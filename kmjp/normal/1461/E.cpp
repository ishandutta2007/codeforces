#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll K,L,R,X,T,Y;
ll ok[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>L>>R>>T>>X>>Y;
	K-=L;
	R-=L;
	
	if(X==Y) {
		if(K>=X||K+X<=R) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	else if(X>Y) {
		if(K+Y<=R) {
			K+=Y;
		}
		K-=X;
		T--;
		__int128 KK=K;
		KK-=__int128(X-Y)*T;
		if(KK<0) return _P("No\n");
		return _P("Yes\n");
	}
	else {
		
		ll day=K/X;
		T-=day;
		K%=X;
		while(1) {
			if(T<=0) return _P("Yes\n");
			if(ok[K]) return _P("Yes\n");
			ok[K]=1;
			if(K+Y>R) return _P("No\n");
			K+=Y;
			ll day=K/X;
			T-=day;
			K%=X;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}