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


int N,K;
int A[505][505];
int C[505*505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int num=0;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		if(C[A[y][x]]++==0) num++;
	}
	if(num<=K) {
		cout<<K-num<<endl;
		return;
	}
	int sy,sx;
	FOR(sy,N) FOR(sx,N) if(sy==0||sx==0) {
		ZERO(C);
		num=0;
		FOR(y,N) FOR(x,N) {
			if(C[A[y][x]]==0) num++;
			C[A[y][x]]++;
		}
		int len=0;
		for(int cy=sy,cx=sx;cy<N&&cx<N;cy++,cx++) {
			while(cy+len<N&&cx+len<N&&num>K) {
				for(y=cy;y<=cy+len;y++) {
					if(--C[A[y][cx+len]]==0) num--;
				}
				for(x=cx;x<cx+len;x++) {
					if(--C[A[cy+len][x]]==0) num--;
				}
				len++;
			}
			if((num==K&&len!=N)||num==K-1) {
				cout<<1<<endl;
				return;
			}
			for(y=cy;y<=cy+len;y++) if(C[A[y][cx]]++==0) num++;
			for(x=cx+1;x<=cx+len;x++) if(C[A[cy][x]]++==0) num++;
			len--;
		}
		
	}
	cout<<2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}