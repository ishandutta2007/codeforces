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
ll A[1010];
int num[1010][1010];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	A[N]=-1LL<<60;
	A[N+1]=1LL<<60;
	N+=2;
	sort(A,A+N);
	
	FOR(i,N-2) M[A[i+1]]++;
	
	int ma=max(M[0],2);
	
	/*
	for(y=N-2;y>=1;y--) for(x=N-2;x>=1;x--) if(x!=y && A[x]>0 && A[y]>0) {
		ll v=A[x]+A[y];
		i=lower_bound(A+y+1,A+N,v)-A;
		if(A[i]==v) num[x][y]=num[y][i]+1;
		ma=max(ma,num[x][y]+2);
	}
	for(y=1;y<N;y++) for(x=1;x<N;x++) if(x!=y && A[x]<0 && A[y]<0) {
		ll v=A[x]+A[y];
		i=upper_bound(A,A+min(x,y),v)-A;
		if(A[i]==v) num[x][y]=num[y][i]+1;
		ma=max(ma,num[x][y]+2);
	}
	*/
	
	for(x=1;x<N-1;x++) for(y=1;y<N-1;y++) if(x!=y) {
		if(A[x]==0 && A[y]==0) continue;
		vector<ll> V;
		V.push_back(A[x]);
		V.push_back(A[y]);
		M[A[x]]--;
		M[A[y]]--;
		int cur=2;
		ll a=A[x],b=A[y];
		int lp=0;
		int ng=0;
		while(1) {
			ll v=a+b;
			if(M.count(v)>0 && M[v]) {
				cur++;
				V.push_back(v);
				M[v]--;
				a=b;
				b=v;
			}
			else {
				break;
			}
		}
		ma=max(ma,cur);
		FORR(r,V) M[r]++;
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}