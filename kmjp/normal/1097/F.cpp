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


int N,Q;
bitset<8192> T[7070],U[7070];
bitset<8192> S[101010];

int ok[7070];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	
	for(i=1;i<=7000;i++) {
		for(x=1;x<=i;x++) if(i%x==0) T[i][x]=1;
		
		ok[i]=1;
		for(x=2;x*x<=i;x++) if(i%(x*x)==0) ok[i]=0;
	}
	for(i=1;i<=7000;i++) {
		for(x=i;x<=7000;x+=i) if(ok[x/i]) U[i][x]=1;
	}
	
	scanf("%d%d",&N,&Q);
	
	string R;
	while(Q--) {
		int v,z;
		scanf("%d%d",&i,&x);
		x--;
		if(i==1) {
			scanf("%d",&v);
			S[x]=T[v];
		}
		else if(i==2 || i==3) {
			scanf("%d%d",&y,&z);
			y--,z--;
			if(i==2) S[x]=S[y]^S[z];
			if(i==3) S[x]=S[y]&S[z];
		}
		else {
			scanf("%d",&v);
			auto a=S[x]&U[v];
			R+=(char)('0'+(a.count()%2));
		}
		/*
		FOR(i,4) {
			FOR(x,6) cout<<S[i][x+1];
			cout<<" ";
		}
		cout<<endl;
		*/
	}
	cout<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}