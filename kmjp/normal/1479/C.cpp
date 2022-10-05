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

int L,R;
int d[32][32];
int N;

vector<ll> D[33];

void add(int f,int t,int v) {
	d[f][t]+=v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R;
	if(R<=30) {
		N=32;
		for(i=0;i<=29;i++) add(i,i+1,1);
		for(i=L;i<=R;i++) {
			add(i-1,31,1);
		}
	}
	else {
		int dif=L-1;
		L-=dif;
		R-=dif;
		int ma=0;
		while((1<<(ma+1))<=R) ma++;
		N=ma+3;
		add(0,1,(1<<ma)-2+dif+1);
		for(i=2;i<=ma+2;i++) {
			if(i==ma+2) add(0,i,1+dif);
			else add(0,i,(1<<(ma+1-i))+dif);
			for(j=i+1;j<=ma+2;j++) {
				if(j==ma+2) x=1;
				else x=1<<(ma+1-j);
				add(i,j,x);
			}
		}
		int R2=R-(1<<ma);
		for(i=2;i<=ma+2;i++) {
			if(i==ma+2) x=1;
			else x=1<<((ma+1)-i);
			
			if(R2>=x) {
				add(1,i,R2-(x-1));
				R2-=x;
			}
		}
	}
	
	/*
	D[0].push_back(0);
	FOR(i,N) {
		FORR(e,D[i]) FOR(j,N) if(d[i][j]) D[j].push_back(e+d[i][j]);
	}
	sort(ALL(D[N-1]));
	FORR(v,D[N-1]) cout<<v<<" ";
	cout<<endl;
	*/
	
	
	cout<<"YES"<<endl;
	int M=0;
	FOR(x,N) FOR(y,N) if(d[x][y]) M++;
	cout<<N<<" "<<M<<endl;
	FOR(x,N) FOR(y,N) if(d[x][y]) cout<<(x+1)<<" "<<(y+1)<<" "<<d[x][y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}