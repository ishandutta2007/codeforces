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
int P[1010101];
int vis[1010101];
int cnt[1010101];

int getmin() {
	bitset<1010100> b;
	static int lef[1010101];
	b[0]=1;
	int j;
	for(int i=1;i<=1000000;i++) {
		if(cnt[i]<100) {
			FOR(j,cnt[i]) b |= b<<i;
		}
		else {
			bitset<1010100> c;
			MINUS(lef);
			for(j=0;j<N;j++) {
				if(b[j]) lef[j]=cnt[i];
				if(lef[j]>=0) c[j]=1;
				if(j+i<N) lef[j+i]=lef[j]-1;
			}
			b=c;
		}
	}
	
	return (b[K]?K:(K+1));
}

int getmax() {
	int left=0;
	int ret=0;
	int k=K;
	for(int i=1;i<=1000000;i++) {
		for(int j=0;j<cnt[i];j++) {
			if(k*2<=i) {
				ret+=k*2;
				k=0;
			}
			else {
				ret+=i/2*2;
				k-=i/2;
				left+=i%2;
			}
		}
	}
	if(k) ret += min(k,left);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	FOR(i,N) scanf("%d",&P[i]), P[i]--;
	
	FOR(i,N) if(vis[i]==0) {
		x = 0;
		y = i;
		while(vis[y]==0) {
			x++;
			vis[y]=1;
			y=P[y];
		}
		cnt[x]++;
	}
	
	cout<<getmin()<<" "<<getmax()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}