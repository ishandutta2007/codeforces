#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int S[1<<17];
ll F[1<<17];
ll mo=1000000007;
ll AB[1<<17];

vector<ll> fft(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(int m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				v[j1]=t1+t2;
				v[j2]=t1-t2;
			}
		}
	}
	if(rev) {
		FOR(i,n) v[i]/=n;
	}
	return v;
}


vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

vector<ll> fft2(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(int m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				
				if(!rev) {
					v[j1]=t2;
					v[j2]=(t1+t2)%mo;
				}
				else {
					v[j1]=(t2-t1+mo)%mo;
					v[j2]=t1;
				}
				
			}
		}
	}
	return v;
}


vector<ll> MultPoly2(vector<ll> P,vector<ll> Q,bool resize=false) {
	P=fft2(P), Q=fft2(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft2(P,true);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=0;
	F[1]=1;
	for(i=2;i<1<<17;i++) F[i]=(F[i-1]+F[i-2])%mo;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&x);
		S[x]++;
	}
	
	int mask;
	FOR(mask,1<<17) {
		for(int i=mask; i>=0; i--) {
			i&=mask;
			AB[mask]+=1LL*S[i]*S[mask^i]%mo;
		}
		AB[mask]=AB[mask]%mo*F[mask]%mo;
	}
	
	vector<ll> D[4];
	FOR(i,1<<17) D[0].push_back(S[i]);
	D[0]=MultPoly(D[0],D[0]);
	
	FOR(mask,1<<17) {
		D[1].push_back(AB[mask]);
		D[2].push_back(S[mask]*F[mask]%mo);
		D[3].push_back(D[0][mask]%mo*F[mask]%mo);
	}
	D[1]=MultPoly2(D[1],D[2]);
	FOR(mask,1<<17) D[1][mask]%=mo;
	D[1]=MultPoly2(D[1],D[3]);
	ll ret=0;
	FOR(i,17) ret+=D[1][1<<i]%mo;
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}