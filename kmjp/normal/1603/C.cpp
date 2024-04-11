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

int t,N,A[101010];
const ll mo=998244353;

pair<int,int> hoge(int nex,int cur) {
	if(cur<=nex) return {cur,0};
	int num=(cur+nex-1)/nex;
	return {cur/num,num-1};
	
}

unordered_map<int,ll> F;
unordered_map<int,ll> T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>t;
	while(t--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		ll ret=0;
		F.clear();
		FOR(i,N) {
			x=A[N-1-i];
			T.clear();
			T[x]=1;
			FORR2(a,b,F) {
				auto p=hoge(a,x);
				(ret+=b*p.second%mo*(N-i))%=mo;
				(T[p.first]+=b)%=mo;
			}
			swap(F,T);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}