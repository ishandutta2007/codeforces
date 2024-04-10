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

const int MAT=50;
ll mo=1000003;
ll ma[50][50],V[50],R[50];
ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int Gauss(int n,ll mat_[MAT][MAT],ll v_[MAT],ll r[MAT]) {
	int i,j,k;
	ll mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) break;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		(v[i]*=rev(mat[i][i]))%=mo;
		for(k=n-1;k>=i;k--) (mat[i][k]*=rev(mat[i][i]))%=mo;
		for(j=i+1;j<n;j++) {
			v[j]=((v[j]-v[i]*mat[j][i]%mo)+mo)%mo;
			for(k=n-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[i][k]*mat[j][i]%mo)+mo)%mo;
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]=((v[i]-mat[i][j]*v[j]%mo)+mo)%mo;
		r[i]=v[i];
	}
	return n;
}

int A[11]={1,2,3,4,5,6,7,8,11,10};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,11) {
		cout<<"? "<<i<<endl;
		cin>>R[i];
		/*
		ll sum=0;
		FOR(j,11) sum+=A[j]*modpow(i,j);
		R[i]=sum%mo;
		cout<<R[i]<<endl;
		*/
		FOR(j,11) ma[i][j]=modpow(i,j);
	}
	
	x=Gauss(11,ma,R,V);
	
	FOR(i,mo) {
		ll sum=0;
		FOR(j,11) sum+=V[j]*modpow(i,j)%mo;
		sum%=mo;
		if(sum==0) {
			cout<<"! "<<i<<endl;
			return;
		}
	}
	cout<<"! -1"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}