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


int N;
int ma;
int ask(int L,int R) {
	cout<<"? "<<(L+1)<<" "<<R<<endl;
	cin>>L;
	return L-1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int L=0,R=N;
	x=ask(L,R);
	int S,T;
	if(x==0) {
		S=0,T=N-1;
	}
	else if(x==N-1) {
		S=N-1,T=0;
	}
	else {
		i=ask(0,x+1);
		if(i==x) S=x,T=0;
		else S=x,T=N-1;
	}
	
	if(S<=T) {
		for(i=18;i>=0;i--) if(T-(1<<i)>S) {
			if(ask(S,T-(1<<i)+1)==S) T-=1<<i;
		}
	}
	else {
		for(i=18;i>=0;i--) if(T+(1<<i)<S) {
			if(ask(T+(1<<i),S+1)==S) T+=1<<i;
		}
	}
	cout<<"! "<<T+1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}