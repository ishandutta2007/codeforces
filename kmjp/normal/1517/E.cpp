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

int T,N;
int A[202020];
ll S[202002];
const ll mo=998244353;

ll slow() {
	int ret=0;
	int mask;
	int i;
	FOR(mask,1<<N) {
		ll sum=0;
		vector<int> B[2];
		FOR(i,N) {
			if(mask&(1<<i)) {
				B[1].push_back(i);
				sum+=A[i];
			}
			else {
				B[0].push_back(i);
				sum-=A[i];
			}
		}
		if(sum<=0) continue;
		if(B[0].size()==3&&B[0][1]-B[0][0]>B[0][2]-B[0][1]) continue;
		if(B[1].size()==3&&B[1][1]-B[1][0]<B[1][2]-B[1][1]) continue;
		ret++;
	}
	
	return ret;
}


ll hoge(vector<int> B, ll dif) {
	ll ret=0;
	int N=B.size();
	int i;
	FOR(i,N) S[i+1]=S[i]+B[i];
	
	ll T=S[N];
	for(int s=1;s<=2;s++) {
		ll CT=T-B[0];
		if(s==2) CT-=B[1];
	int L,R;
		for(L=R=s;L<N;L+=2) {
			while(R+2<=N-1&&(CT+dif-B[R+1]>T-(CT-B[R+1]))) CT-=B[R+1], R+=2;
			while(L<R&&(CT+dif<=T-(CT))) CT+=B[R-1], R-=2;
			if(CT+dif<=T-CT) break;
			ret+=((R-L)/2+1);
			CT-=B[L];
			if(L==R) R+=2, CT-=B[L+1];
		}
	}
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll S=0;
		FOR(i,N) {
			cin>>A[i];
			S+=A[i];
		}
		
		if(N<=4) {
			cout<<slow()<<endl;
			continue;
		}
		ll ret=0;
		ll T=A[0];
		for(i=1;i<=N;i++) {
			if(T>S-T) ret++;
			T+=A[i];
		}
		FOR(x,2) FOR(y,2) {
			ll sum=0;
			vector<int> B;
			FOR(i,N) {
				if(i==0&&x==1) sum+=A[i];
				else if(i==N-1&&y==1) sum-=A[i];
				else B.push_back(A[i]);
			}
			ret+=hoge(B,sum);
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}