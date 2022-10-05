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
int V[2020][2020];

template<class V,int MA> class BIT_2d {
public:
	V val[1<<MA][1<<MA];
	BIT_2d(){ZERO(val);};
	V total(int x,int y) {
		V s=0;
		for(int i=x+1;i>0;i-=i&-i) for(int j=y+1;j>0;j-=j&-j) s+=val[i-1][j-1];
		return s;
	}
	void update(int x,int y,V v) {
		for(int i=x+1;i<=1<<MA;i+=i&-i) for(int j=y+1;j<=1<<MA;j+=j&-j) val[i-1][j-1]+=v;
	}
};
BIT_2d<int,12> bit;

int win[2020][2020];


void solve() {
	int i,j,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<pair<int,int>> P;
	FOR(y,N) FOR(x,N) {
		cin>>V[y][x];
		P.push_back({-V[y][x],y*2000+x});
	}
	sort(ALL(P));
	FORR2(a,b,P) {
		y=b/2000;
		x=b%2000;
		int p=x+y+1;
		int q=x-y+2000+1;
		
		int tot=bit.total((1<<12)-1,(1<<12)-1);
		int p2=min(p+K,4040),p1=max(p-K-1,0);
		int q2=min(q+K,4040),q1=max(q-K-1,0);
		tot-=bit.total(p2,q2)-bit.total(p1,q2)-bit.total(p2,q1)+bit.total(p1,q1);
		if(tot==0) {
			win[y][x]=1;
			bit.update(p,q,1);
		}
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<(win[y][x]?'M':'G');
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}