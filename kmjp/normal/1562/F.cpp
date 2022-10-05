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


int T;
int N;
int P[505050];
map<pair<int,int>,ll> memo;
ll C[105][105];
int ret[101010];

const int prime_max = 200000;
vector<int> prime;
int NP,divp[prime_max+5];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

map<ll,int> memo2;

ll ask(int a,int b) {
	if(a>b) swap(a,b);
	if(memo.count({a,b})==0) {
		ll ret=0;
		if(P[0]) {
			ret=1LL*P[a]*P[b]/__gcd(P[a],P[b]);
		}
		else {
			cout<<"? "<<(a+1)<<" "<<(b+1)<<endl;
			cin>>ret;
		}
		memo[{a,b}]=ret;
	}
	return memo[{a,b}];
}

void small() {
	int x,y;
	int pre;
	set<int> cand;
	FOR(x,N) FOR(y,x) {
		C[x][y]=C[y][x]=ask(x,y);
	}
	FOR(x,N) cand.insert(x);
	int pt;
	while(cand.size()>2) {
		ll ma=0;
		int x,y;
		FORR(a,cand) FORR(b,cand) if(a<b) {
			if(C[a][b]>ma) {
				x=a;
				y=b;
				ma=C[a][b];
			}
		}
		pre=memo2[ma];
		int ok[2]={1,1};
		FORR(a,cand) {
			if(a!=x&&C[a][x]%pre) ok[0]=0;
			if(a!=y&&C[a][y]%pre) ok[1]=0;
		}
		if(ok[0]) {
			pt=x;
			ret[x]=pre;
			cand.erase(x);
		}
		else {
			pt=y;
			ret[y]=pre;
			cand.erase(y);
		}
		
		
	}
	FORR(a,cand) {
		if(C[a][pt]==1LL*pre*(pre-1)) ret[a]=pre-1;
		else ret[a]=pre-2;
	}
	
}

void large() {
	int tar=0,tx,ty,i;
	FOR(i,500) {
		int x=rand()%N;
		int y=rand()%N;
		if(x==y) continue;
		ll a=ask(x,y);
		FORR(pr,prime) if(a%pr==0) {
			if(tar<pr) {
				tar=pr;
				tx=x;
				ty=y;
			}
		}
		
	}
	int fix=-1;
	FOR(i,N) {
		if(i==tx) continue;
		if(i==ty) continue;
		ll a=ask(i,tx);
		ll b=ask(i,ty);
		if(a%tar==0&&b%tar) {
			fix=tx;
			break;
		}
		if(b%tar==0&&a%tar) {
			fix=ty;
			break;
		}
	}
	ret[fix]=tar;
	FOR(i,N) if(i!=fix) {
		ret[i]=ask(i,fix)/tar;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,201010) memo2[1LL*i*(i+1)]=i+1;
	cprime();
	srand(time(NULL));
	
	cin>>T;
	while(T--) {
		memo.clear();
		
		cin>>N;
		FOR(i,N) ret[i]=0;
		if(N<=100) {
			small();
		}
		else {
			large();
		}
		
		
		cout<<"!";
		FOR(i,N) cout<<" "<<ret[i];
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}