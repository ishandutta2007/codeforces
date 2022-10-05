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

int N,Q;
int P[101010];
int R[101010];
int S[101010];

const int DI=30;
void update(int i) {
	int x=i,y;
	FOR(y,DI) x=P[x];
	S[i]=x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		R[P[i]]=i;
	}
	FOR(i,N) update(i);
	
	while(Q--) {
		cin>>i>>x>>y;
		
		if(i==1) {
			x--,y--;
			swap(P[x],P[y]);
			R[P[y]]=y;
			R[P[x]]=x;
			FOR(j,DI+1) {
				update(x);
				update(y);
				x=R[x];
				y=R[y];
			}
			
		}
		else {
			x--;
			while(y>=DI) x=S[x],y-=DI;
			while(y--) x=P[x];
			cout<<x+1<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}