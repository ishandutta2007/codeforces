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


string S,X;

using VT = string;

vector<ll> mos={1000000027,1000000007,3571,10009};
struct RollingHash {
	static vector<ll> pmo[4];
	VT s; int l; vector<ll> hash_[4];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		FOR(i,4) hash_[i]=vector<ll>(1,0);
		if(pmo[0].empty()) FOR(i,4) pmo[i].push_back(1);
		FOR(j,4) {
			FOR(i,l) hash_[j].push_back((hash_[j].back()*10+s[i])%mos[j]);
		}
	}
	vector<ll> hash(int l,int r) { // s[l..r]
		if(l>r) return {0,0,0,0};
		int i;
		while(pmo[0].size()<r+2) {
			FOR(i,4) pmo[i].push_back(pmo[i].back()*10%mos[i]);
		}
		vector<ll> ret;
		FOR(i,4) {
			ret.push_back((hash_[i][r+1]+(mos[i]-hash_[i][l]*pmo[i][r+1-l]%mos[i]))%mos[i]);
		}
		return ret;
	}
	vector<ll> hash(VT s) { init(s); return hash(0,s.size()-1); }
};
vector<ll> RollingHash::pmo[4];

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

RollingHash rh;
int L,N;
vector<ll> XH;
void check(int i,int x,int y) {
	auto a=rh.hash(i,i+x-1);
	auto b=rh.hash(i+x,i+x+y-1);
	int j;
	FOR(j,4) a[j]=(a[j]+b[j])%mos[j];
	
	
	if(a==XH) {
		string C(N,'\0');
		for(int m=N-1,t=i+x-1;m>=0&&t>=i;m--,t--) {
			C[m]+=S[t];
		}
		for(int m=N-1,t=i+x+y-1;m>=0&&t>=i+x;m--,t--) {
			C[m]+=S[t];
			if(m&&C[m]>=10) C[m]-=10,C[m-1]++;
		}
		if(C!=X.substr(0,N)) return;
		cout<<(i+1)<<" "<<(i+x)<<endl;
		cout<<(i+x+1)<<" "<<(i+x+y)<<endl;
		exit(0);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X;
	L=S.size();
	N=X.size();
	
	FORR(c,S) c-='0';
	FORR(c,X) c-='0';
	
	XH=rh.hash(X);
	X+="$"+S;
	auto Z=Zalgo(X);
	
	rh.init(S);
	FOR(i,L) {
		FOR(j,4) {
			x=N-(j%2);
			y=N-(j/2%2);
			
			if(i+x+y>L) continue;
			if(x<1||y<1) continue;
			check(i,x,y);
		}
	}
	for(i=0;i+N<=L;i++) {
		int lcp=Z[N+1+i];
		FOR(j,2) {
			int add=N-lcp-j;
			if(add<=0) continue;
			
			
			if(i>=add) {
				check(i-add,add,N);
			}
			if(i+N+add<=L) {
				check(i,N,add);
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