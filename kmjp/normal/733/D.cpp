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
int A[101010],B[101010],C[101010];
pair<int,int> AB[101010],BC[101010],CA[101010];
int X,Y;
int ma;
map<pair<int,int>,pair<int,int>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	X=-1,Y=-1;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		if(min(A[i],min(B[i],C[i]))>ma) X=i+1, ma=min(A[i],min(B[i],C[i])), Y=-1;
		AB[i]={min(A[i],B[i]),max(A[i],B[i])};
		BC[i]={min(B[i],C[i]),max(B[i],C[i])};
		CA[i]={min(C[i],A[i]),max(C[i],A[i])};
		
		if(M[AB[i]].first>0) {
			x = min(A[i],min(B[i],C[i]+M[AB[i]].first));
			if(x>ma) ma=x, X=i+1, Y=M[AB[i]].second+1;
		}
		if(M[BC[i]].first>0) {
			x = min(A[i]+M[BC[i]].first,min(B[i],C[i]));
			if(x>ma) ma=x, X=i+1, Y=M[BC[i]].second+1;
		}
		if(M[CA[i]].first>0) {
			x = min(A[i],min(B[i]+M[CA[i]].first,C[i]));
			if(x>ma) ma=x, X=i+1, Y=M[CA[i]].second+1;
		}
		
		M[AB[i]]=max({M[AB[i]],{C[i],i}});
		M[BC[i]]=max({M[BC[i]],{A[i],i}});
		M[CA[i]]=max({M[CA[i]],{B[i],i}});
	}
	
	if(Y==-1) _P("%d\n%d\n",1,X);
	else _P("%d\n%d %d\n",2,X,Y);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}