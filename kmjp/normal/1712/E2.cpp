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
ll num[202020],pat[202020];
int L[202020],R[202020];
vector<int> ev[202020];
ll ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=200000;i++) {
		for(j=2*i;j<=200000;j+=i) num[j]++;
		// (3:4:6)
		if(i%3==0&&i*2<=200000) pat[2*i]++;
		// (6:10:15)
		if(i%6==0&&i*5/2<=200000) pat[i*5/2]++;
	}
	for(i=1;i<=200000;i++) {
		pat[i]+=num[i]*(num[i]-1)/2;
		bt.add(i,pat[i]);
	}
	
	
	cin>>T;
	FOR(i,T) {
		cin>>L[i]>>R[i];
		ev[L[i]].push_back(i);
	}
	for(i=1;i<=200000;i++) {
		FORR(e,ev[i]) {
			ll a=R[e]-L[e]+1;
			ret[e]=a*(a-1)*(a-2)/6-bt(R[e]);
		}
		
		for(j=2*i;j<=200000;j+=i) {
			bt.add(j,-pat[j]);
			pat[j]-=num[j]*(num[j]-1)/2;
			num[j]--;
			pat[j]+=num[j]*(num[j]-1)/2;
			bt.add(j,pat[j]);
		}
		// (3:4:6)
		if(i%3==0&&i*2<=200000) {
			pat[2*i]--;
			bt.add(2*i,-1);
		}
		// (6:10:15)
		if(i%6==0&&i*5/2<=200000) {
			pat[i*5/2]--;
			bt.add(i*5/2,-1);
		}
	}
	FOR(i,T) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}