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

int H,W;
vector<int> A[202020];
int num[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) {
			cin>>i;
			A[y].push_back(i-1);
		}
	}
	int ret=0;
	FOR(x,W) {
		FOR(y,H) {
			int ty=A[y][x]/W;
			int tx=A[y][x]%W;
			if(tx==x && A[y][x]<H*W) {
				if(y>=ty) num[y-ty]++;
				else num[H+y-ty]++;
			}
		}
		int mi=1010101;
		FOR(y,H) {
			mi=min(mi,y+H-num[y]);
			num[y]=0;
		}
		ret+=mi;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}