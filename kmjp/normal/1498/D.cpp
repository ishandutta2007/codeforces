#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int T;
ll X,Y;
int D[101010][202];
int lef[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	D[0][0]=1;
	
	FOR(i,N) {
		cin>>T>>X>>Y;
		MINUS(lef);
		if(T==1) {
			X=(X+99999)/100000;
			FOR(j,M+1) {
				if(D[j][i]) lef[j]=Y;
				if(j+X<=M) lef[j+X]=max(-1,lef[j]-1);
				if(lef[j]>=0) D[j][i+1]=1;
				
			}
		}
		else {
			FOR(j,M+1) {
				if(D[j][i]) lef[j]=Y;
				ll nex=(j*X+99999)/100000;
				if(nex<=M) lef[nex]=max(-1,lef[j]-1);
				if(lef[j]>=0) D[j][i+1]=1;
			}
		}
	}
	
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(D[i][j]) {
				cout<<j<<" ";
				break;
			}
		}
		if(j==N+1) cout<<-1<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}