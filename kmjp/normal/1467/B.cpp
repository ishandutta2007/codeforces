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
int N,A[303030];

int num(int cur) {
	if(cur<1||cur>=N-1) return 0;
	if(A[cur-1]<A[cur]&&A[cur]>A[cur+1]) return 1;
	if(A[cur-1]>A[cur]&&A[cur]<A[cur+1]) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		int cur=0;
		FOR(i,N) cur+=num(i);
		int ret=cur;
		FOR(i,N) {
			cur-=num(i-1);
			cur-=num(i);
			cur-=num(i+1);
			x=A[i];
			FOR(y,3) {
				if(i) {
					A[i]=A[i-1]+y-1;
					cur+=num(i-1);
					cur+=num(i);
					cur+=num(i+1);
					ret=min(ret,cur);
					cur-=num(i-1);
					cur-=num(i);
					cur-=num(i+1);
					
				}
				if(i+1<N) {
					A[i]=A[i+1]+y-1;
					cur+=num(i-1);
					cur+=num(i);
					cur+=num(i+1);
					ret=min(ret,cur);
					cur-=num(i-1);
					cur-=num(i);
					cur-=num(i+1);
					
				}
			}
			A[i]=x;
			cur+=num(i-1);
			cur+=num(i);
			cur+=num(i+1);
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