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
int A[101010];
int cnt[101010],U[101010];
vector<int> D[101010];

int cop(int v) {
	int ret=0;
	FORR(d,D[v]) ret+=cnt[d]*U[d];
	return ret;
}

void add(int d,int v) {
	FORR(c,D[d]) cnt[c]+=v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) D[j].push_back(i);
		
		if(i==1) U[i]=1;
		else if(i/D[i][1]%D[i][1]==0) U[i]=0;
		else U[i]-=U[i/D[i][1]];
	}
	
	ll ma=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A[x]++;
		if(A[x]>=2) ma=max(ma,(ll)x);
	}
	for(i=1;i<=100000;i++) {
		vector<int> V;
		for(j=100000/i;j>0;j--) if(A[j*i]) {
			while(cop(j)) {
				if(__gcd(j,V.back())==1) ma=max(ma,1LL*j*V.back()*i);
				add(V.back(),-1);
				V.pop_back();
			}
			V.push_back(j);
			add(j,1);
		}
		FORR(v,V) add(v,-1);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}