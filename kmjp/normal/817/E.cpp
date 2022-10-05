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

struct node {
	int cnt;
	int L,R;
};

int Q;
int N;
int V[101010];
vector<node> P[30];

void add(int b,int cur,int v,int cnt) {
	node& n=P[b][cur];
	if(b==0) {
		n.cnt += cnt;
		return;
	}
	if(v & (1<<(b-1))) {
		if(n.L==-1) {
			n.L=P[b-1].size();
			P[b-1].resize(n.L+1);
			P[b-1][n.L].cnt = 0;
			P[b-1][n.L].L = P[b-1][n.L].R = -1;
		}
		add(b-1,n.L,v,cnt);
	}
	else {
		if(n.R==-1) {
			n.R=P[b-1].size();
			P[b-1].resize(n.R+1);
			P[b-1][n.R].cnt = 0;
			P[b-1][n.R].L = P[b-1][n.R].R = -1;
		}
		add(b-1,n.R,v,cnt);
	}
	
	n.cnt=0;
	if(n.L>=0) n.cnt += P[b-1][n.L].cnt;
	if(n.R>=0) n.cnt += P[b-1][n.R].cnt;
}

int walk(int b,int cur,int p,int l) {
	node& n=P[b][cur];
	if(b==0) return 0;
	
	int ret=0;
	if(l & (1<<(b-1))) {
		if(p & (1<<(b-1))) {
			if(n.L>=0) ret += P[b-1][n.L].cnt;
			if(n.R>=0) ret += walk(b-1,n.R,p,l);
		}
		else {
			if(n.L>=0) ret += walk(b-1,n.L,p,l);
			if(n.R>=0) ret += P[b-1][n.R].cnt;
		}
	}
	else {
		if(p & (1<<(b-1))) {
			if(n.L>=0) ret += walk(b-1,n.L,p,l);
		}
		else {
			if(n.R>=0) ret += walk(b-1,n.R,p,l);
		}
	}
	return ret;
		
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	P[29].resize(1);
	P[29][0].cnt=0;
	P[29][0].L=P[29][0].R=-1;
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d",&i,&j);
		if(i==1) {
			add(29,0,j,1);
		}
		else if(i==2) {
			add(29,0,j,-1);
		}
		else {
			scanf("%d",&k);
			cout<<walk(29,0,j,k)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}