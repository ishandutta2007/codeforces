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
int N;
int A[101010];

int memo[2][2][4][2];

int hoge(int x,int y,int k,int r) {
	if(memo[x][y][k][r]>=0) return memo[x][y][k][r];
	int ret=0;
	if(k && hoge(y,x^1,k-1,r)==0) ret=1;
	if(r && hoge(y,x,k,r-1)==0) ret=1;
	
	//cout<<x<<y<<k<<r<<" "<<ret<<endl;
	return memo[x][y][k][r]=ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	memo[1][0][0][0]=1;
	memo[0][1][0][0]=0;
	FOR(x,2) FOR(y,2) FOR(k,4) FOR(r,2) if((x+y+k)%2) hoge(x,y,k,r);
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		int x=0;
		FOR(i,N) {
			cin>>A[i];
			x^=A[i];
		}
		
		if(x==0) {
			cout<<"DRAW"<<endl;
		}
		else {
			y=1;
			while(y*2<=x) y*=2;
			
			int num=0;
			FOR(i,N) if(A[i]&y) num++;
			
			if(hoge(0,0,num%4,(N-num)%2)) {
				cout<<"WIN"<<endl;
			}
			else {
				cout<<"LOSE"<<endl;
			}
			
		} 
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}