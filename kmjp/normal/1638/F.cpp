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
ll H[1010101];
ll mi[10101];
ll ma;
ll L[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>H[i+1];
	
	// separate
	for(i=0;i<=N;i++) {
		ll a=H[i];
		L[i]=a;
		for(j=i-1;j>=0;j--) {
			a=min(a,H[j]);
			L[i]=max(L[i],a*(i+1-j));
		}
		
		ll r=H[i];
		a=H[i];
		for(j=i+1;j<=N+1;j++) {
			a=min(a,H[j]);
			r=max(r,a*(j-i+1));
		}
		FOR(j,i) ma=max(ma,r+L[j]);
	}
	
	for(i=1;i<=N;i++) {
		int TL=i,TR=i;
		while(H[TL-1]>=H[i]) TL--;
		while(H[TR+1]>=H[i]) TR++;
		ma=max(ma,H[i]*(TR-TL+1));
		mi[i]=H[i];
		for(j=i+1;j<=N+1;j++) mi[j]=min(mi[j-1],H[j]);
		for(j=i-1;j>=0;j--) mi[j]=min(mi[j+1],H[j]);

		// accumulated
		ll a=H[i];
		for(int L=i,R=i;L>=1;L--) {
			a=min(a,H[L]);
			while(H[R+1]>=a) R++;
			ma=max(ma,a*(R-L+1)+(H[i]-a)*(TR-TL+1));
		}
		a=H[i];
		for(int L=i,R=i;R<=N+1;R++) {
			a=min(a,H[R]);
			while(H[L-1]>=a) L--;
			ma=max(ma,a*(R-L+1)+(H[i]-a)*(TR-TL+1));
		}
		// cross
		a=H[i];
		ll rma=0;
		for(int L=i,R=N+1;L>=1;L--) {
			a=min(a,H[L]);
			ll dif=H[i]-a;
			while(R>TR&&mi[R]<dif) {
				rma=max(rma,mi[R]*(R-TL+1));
				R--;
			}
			rma=max(rma,dif*(R-TL+1));
			ma=max(ma,a*(TR-L+1)+rma);
		}
		a=H[i];
		rma=0;
		for(int L=0,R=i;R<=N;R++) {
			a=min(a,H[R]);
			ll dif=H[i]-a;
			while(L<TL&&mi[L]<dif) {
				rma=max(rma,mi[L]*(TR-L+1));
				L++;
			}
			rma=max(rma,dif*(TR-L+1));
			ma=max(ma,rma+a*(R-TL+1));
		}
	}
	
	
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}