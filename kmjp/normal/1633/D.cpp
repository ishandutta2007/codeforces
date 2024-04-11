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

int T,N,K;
int B[1010],C[1010];

int step[2010];
ll from[1000*12+5];
ll to[1000*12+5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1005) step[i]=1010101;
	step[1]=0;
	for(i=1;i<=1000;i++) {
		for(j=1;j<=i;j++) step[i+i/j]=min(step[i+i/j],step[i]+1);
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		K=min(K,N*12);
		vector<int> cand[15];
		
		MINUS(from);
		from[0]=0;
		FOR(i,N) cin>>B[i];
		
		FOR(i,N) {
			cin>>C[i];
			
			if(B[i]==1) {
				from[0]+=C[i];
			}
			else {
				cand[step[B[i]]].push_back(C[i]);
			}
		}
		for(i=1;i<=12;i++) {
			MINUS(to);
			sort(ALL(cand[i]));
			reverse(ALL(cand[i]));
			FOR(j,K+1) if(from[j]>=0) {
				ll s=0;
				for(x=0;x<=cand[i].size();x++) {
					to[j+x*i]=max(to[j+x*i],from[j]+s);
					if(x<cand[i].size()) s+=cand[i][x];
				}
			}
			swap(from,to);
		}
		cout<<*max_element(from,from+K+1)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}