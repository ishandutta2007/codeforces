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

int N,K;
int A[1010];
ll pat[101010];

ll from[1010],S[1010],to[1010];
ll mo=998244353;

ll hoge(int d) {
	ZERO(from);
	ZERO(to);
	int i,j,x,y;
	FOR(i,N) from[i]=1;
	FOR(i,K-1) {
		S[0]=from[0];
		for(j=1;j<N;j++) (S[j]=S[j-1]+from[j])%=mo;
		int x=-1;
		FOR(y,N) {
			while(x<y && A[y]-A[x+1]>=d) x++;
			if(x==-1) to[y]=0;
			else to[y]=S[x];
		}
		swap(from,to);
	}
	ll sum=0;
	FOR(i,N) sum+=from[i];
	return sum%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	for(i=1;i<=100001/(K-1);i++) {
		pat[i]=hoge(i);
	}
	ll ret=0;
	for(i=1;i<=100001/(K-1);i++) {
		ret+=i*(pat[i]-pat[i+1]+mo)%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}