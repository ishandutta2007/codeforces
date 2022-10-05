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

int H,W,Q;
int A,B,C,D,h,w;
struct node { int v; node *L,*R,*U,*D;};
node V[1010][1010];

node* walk(int y,int x) {
	node* n=&V[0][0];
	while(y--) n=n->D;
	while(x--) n=n->R;
	return n;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	scanf("%d%d%d",&H,&W,&Q);
	FOR(y,H) FOR(x,W) scanf("%d",&V[y+1][x+1].v);
	FOR(y,H+2) FOR(x,W+2) {
		if(x<W+1) V[y][x].R=&V[y][x+1];
		if(x>0) V[y][x].L=&V[y][x-1];
		if(y<H+1) V[y][x].D=&V[y+1][x];
		if(y>0) V[y][x].U=&V[y-1][x];
	}
	
	while(Q--) {
		scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&h,&w);
		
		node *n1 = walk(A,B);
		node *n2 = walk(C,D);
		FOR(i,w) {
			swap(n1->U,n2->U);
			n1->U->D=n1;
			n2->U->D=n2;
			n1=n1->R;
			n2=n2->R;
		}
		n1=n1->L;
		n2=n2->L;
		FOR(i,h) {
			swap(n1->R,n2->R);
			n1->R->L=n1;
			n2->R->L=n2;
			n1=n1->D;
			n2=n2->D;
		}
		n1=n1->U;
		n2=n2->U;
		FOR(i,w) {
			swap(n1->D,n2->D);
			n1->D->U=n1;
			n2->D->U=n2;
			n1=n1->L;
			n2=n2->L;
		}
		n1=n1->R;
		n2=n2->R;
		FOR(i,h) {
			swap(n1->L,n2->L);
			n1->L->R=n1;
			n2->L->R=n2;
			n1=n1->U;
			n2=n2->U;
		}
	}
	
	FOR(y,H) {
		node *n = walk(y+1,1);
		FOR(x,W) _P("%d%c",n->v,(x==W-1)?'\n':' '), n=n->R;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}