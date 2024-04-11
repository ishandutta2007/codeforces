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

ll sum(vector<int> V) {
	static int p[505050];
	int i;
	ll sum=0;
	MINUS(p);
	FOR(i,2*N) {
		if(p[V[i]]==-1) p[V[i]]=i;
		else {
			sum+=1LL*(N-V[i])*abs((i-p[V[i]])+V[i]-N);
		}
	}
	cout<<sum<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	vector<int> V;
	if(N%2==0) {
		for(i=1;i<N;i+=2) V.push_back(i);
		for(i=N-1;i>0;i-=2) V.push_back(i);
		for(i=2;i<N;i+=2) V.push_back(i);
		V.push_back(N);
		for(i=N-2;i>0;i-=2) V.push_back(i);
		V.push_back(N);
	}
	else {
		for(i=1;i<N;i+=2) V.push_back(i);
		for(i=N;i>0;i-=2) V.push_back(i);
		V.push_back(N);
		for(i=2;i<N;i+=2) V.push_back(i);
		for(i=N-1;i>0;i-=2) V.push_back(i);
	}
	//sum(V);
	FORR(r,V) _P("%d ",r);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}