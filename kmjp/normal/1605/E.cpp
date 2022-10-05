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


int N;
int A[202020],B[202020];
int D[202020],D2[202020];
vector<int> C[2];

ll RS[1010101];
ll LS[1010101];
ll sum[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	for(i=2;i<=N;i++) A[i]=1;
	for(i=2;i<=N;i++) B[i]=0;
	
	for(i=2;i<=N;i++) {
		D[i]=B[i]-A[i];
		for(j=i;j<=N;j+=i) A[j]+=D[i];
	}
	
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) cin>>B[i+1];
	
	B[1]=A[1];
	ll base=0;
	for(i=2;i<=N;i++) {
		D2[i]=B[i]-A[i];
		for(j=i;j<=N;j+=i) A[j]+=D2[i];
		
		if(D[i]==0) {
			base+=abs(D2[i]);
		}
		else {
			if(D[i]==-1) {
				x=A[1]+D2[i];
			}
			else {
				x=A[1]-D2[i];
			}
			
			if(x<0) {
				base+=-x-1;
				RS[0]++;
			}
			else if(x>1000000) {
				base+=x-1000000-1;
				LS[1000000]++;
			}
			else {
				RS[x+1]++;
				LS[x-1]++;
			}
		}
	}
	ll a=base;
	int cur=0;
	for(i=0;i<=1000000;i++) {
		cur+=RS[i];
		a+=cur;
		sum[i]+=a;
	}
	a=cur=0;
	for(i=1000000;i>=0;i--) {
		cur+=LS[i];
		a+=cur;
		sum[i]+=a;
	}
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x;
		cout<<sum[x]+abs(x-A[1])<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}