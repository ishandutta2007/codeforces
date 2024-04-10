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
int A[1010101];

int hoge(int V,int L,int D) {
	if(L>D) swap(L,D);
	if(L>=V && D>=V) return V-1;
	if(D>=V) return L;
	return max(0,L+D-V+1);
}

int num(int V,int L,int R,int U,int D) {
	int tot=0;
	if(V==0) return 1;
	if(L<0 || R<0 || U<0 || D<0) return -1;
	if(L>=V) tot++;
	if(R>=V) tot++;
	if(U>=V) tot++;
	if(D>=V) tot++;
	tot+=hoge(V,L,D);
	tot+=hoge(V,L,U);
	tot+=hoge(V,R,D);
	tot+=hoge(V,R,U);
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	int ma=0;
	FOR(i,T) scanf("%d",&x), A[x]++, ma=max(ma,x);
	
	vector<int> C={0,1,2,3};
	do {
		vector<int> V={1<<20,1<<20,1<<20,1<<20};
		for(i=1;;i++) {
			if(max({V[C[0]],V[C[1]],V[C[2]]})<1<<20) break;
			while(A[i]<num(i,V[0],V[1],V[2],V[3])) {
				if(max({V[C[0]],V[C[1]],V[C[2]]})<1<<20) break;
				FOR(j,4) if(V[C[j]]==1<<20) {
					V[C[j]]=i-1;
					break;
				}
			}
		}
		
		if(C[3]==0) V[0]=T/(V[2]+V[3]+1)-(V[1]+1);
		if(C[3]==1) V[1]=T/(V[2]+V[3]+1)-(V[0]+1);
		if(C[3]==2) V[2]=T/(V[0]+V[1]+1)-(V[3]+1);
		if(C[3]==3) V[3]=T/(V[0]+V[1]+1)-(V[2]+1);
		
		int ok=1;
		FOR(i,ma+1) if(num(i,V[0],V[1],V[2],V[3])!=A[i]) ok=0;
		
		if(ok) {
			cout<<V[0]+V[1]+1<<" "<<V[2]+V[3]+1<<endl;
			cout<<V[0]+1<<" "<<V[2]+1<<endl;
			return;
		}
		
	} while(next_permutation(ALL(C)));
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}