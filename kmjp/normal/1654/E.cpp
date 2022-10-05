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

int N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	int ma=min(N,2);
	
	FOR(j,2) {
		
		for(int d=0;d<=350;d++) {
			vector<int> B;
			FOR(i,N) B.push_back(A[i]-i*d);
			sort(ALL(B));
			int pre=-1<<30;
			int cnt=0;
			FORR(b,B) {
				if(b!=pre) cnt=0;
				cnt++;
				pre=b;
				ma=max(ma,cnt);
			}
		}
		
		FOR(i,N) {
			vector<int> B;
			for(l=1;l<=350&&i+l<N;l++) {
				if((A[i+l]-A[i])%l==0) B.push_back((A[i+l]-A[i])/l);
			}
			sort(ALL(B));
			int pre=-1<<30;
			int cnt=0;
			FORR(b,B) {
				if(b!=pre) cnt=0;
				cnt++;
				pre=b;
				ma=max(ma,cnt+1);
			}
		}
		
		
		reverse(A,A+N);
	}
	
	
	
	
	cout<<N-ma<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}