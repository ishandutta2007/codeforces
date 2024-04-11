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

template<int um> class UF {
	public:
	vector<int> par;
	UF() {for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		x=operator[](x);
		y=operator[](y);
		return par[x]=par[y]=max(x,y);
	}
};
UF<1<<15> uf;

int H,W;

string S;
bitset<1<<14> A,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int V=0;
	
	FOR(y,H) {
		FOR(x,W) if(A[x]) uf.par[x]=uf[x+W]-W;
		FOR(x,W) uf.par[x+W]=x+W;
		cin>>S;
		FORR(c,S) {
			if(c>='0' && c<='9') c-='0';
			else c=c-'A'+10;
		}
		FOR(x,W) {
			if(S[x/4]&(1<<(3-x%4))) {
				V++;
				B[x]=1;
				if(A[x]&&uf[x]!=uf[x+W]) V--, uf(x,x+W);
			}
			else B[x]=0;
		}
		FOR(x,W-1) {
			if(B[x]&&B[x+1]&&uf[x+W]!=uf[x+W+1]) {
				V--;
				uf(x+W,x+W+1);
			}
		}
		
		A=B;
	}
	
	cout<<V<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}