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
ll N,K;

/*
int memo[101];

int win(int cur) {
	if(memo[cur]>=0) return memo[cur];
	if(cur==0) return 0;
	if(win(cur-1)==0) return memo[cur]=1;
	if(cur>=2 && win(cur-2)==0) return memo[cur]=1;
	if(cur>=K && win(cur-K)==0) return memo[cur]=1;
	return memo[cur]=0;
}
*/
int win2(int cur) {
	if(cur==K) return 1;
	if(cur<=K) return cur%3!=0;
	if(K%3!=0) return cur%3!=0;
	cur%=(K+1);
	if(cur==K) return 1;
	if(cur%3==0) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	for(K=3;K<=100;K++) {
		cout<<K<<" ";
		MINUS(memo);
		for(N=0;N<=100;N++) {
			cout<<(win(N)==win2(N));
		}
		cout<<endl;
	}
	*/
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(win2(N)) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}