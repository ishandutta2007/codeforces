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

int N,M,P;
string S[202020];

int sum[1<<15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	FOR(y,N) cin>>S[y];
	vector<int> ret;
	srand(time(NULL)+i);
	FOR(i,20) {
		x=(rand()+1LL*rand()*rand()+i)%N;
		vector<int> cand;
		ZERO(sum);
		FOR(j,M) if(S[x][j]=='1') cand.push_back(j);
		P=cand.size();
		FOR(j,N) {
			int mask=0;
			FOR(k,cand.size()) if(S[j][cand[k]]=='1') mask|=1<<k;
			sum[mask]++;
		}
		
		FOR(j,P) {
			FOR(y,1<<P) if((y&(1<<j))==0) sum[y]+=sum[y|(1<<j)];
		}
		FOR(y,1<<P) if(sum[y]>=(N+1)/2) {
			if(__builtin_popcount(y)>ret.size()) {
				ret.clear();
				FOR(j,P) if(y&(1<<j)) ret.push_back(cand[j]);
			}
		}
		
	}
	
	string R(M,'0');
	FORR(v,ret) R[v]='1';
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}