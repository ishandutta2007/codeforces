#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=201100,mod=998244353;
int a[N];
ll ssm[N],res;
int n;

void solve(){
	for(int j=0;j<2;++j)for(int i=n+10-j;i>=0;i-=2)ssm[i]=a[i]+ssm[i+2];
	ll csm=accumulate(a,a+n,0ll);
	ll psm=0;
	// PPPCCC
	for(int i=0;i<n;++i){
		csm-=a[i];
		psm+=a[i];
		if(psm>csm)++res;
	}
//	cerr<<"before "<<res<<endl;
	// PCCC CPCP
	if(n>=3){
		ll csum=0,psum=a[0];
		for(int i=1;i+1<n;++i){
			// no C
			int l=0,r=(n-i)/2;
			while(l<r){
				int m=(l+r)/2;
				int midx=2*m+i; // idx of CPPPP
				ll tc=csum+ssm[i]-ssm[midx+2];
				ll tp=psum+ssm[i+1]-ssm[midx+3];
				tp+=ssm[midx+2]+ssm[midx+3];
				if(tc<tp)l=m+1;
				else r=m;
			}
			res+=l;
			// C at the end
			if(i+2<n){
				int l=0,r=(n-i-1)/2;
				while(l<r){
					int m=(l+r)/2;
					int midx=2*m+i; // idx of CPPPPPC
					ll tc=csum+ssm[i]-ssm[midx+2];
					ll tp=psum+ssm[i+1]-ssm[midx+3];
					tp+=ssm[midx+2]+ssm[midx+3]-a[n-1];
					tc+=a[n-1];
//					cerr<<"binary "<<m<<" "<<tp<<" "<<tc<<endl;
					if(tc<tp)l=m+1;
					else r=m;
				}
//				cerr<<l<<endl;
				res+=l;
			}
			csum+=a[i];
		}
	}
//	cerr<<"starting with 1: "<<res<<endl;
	psm=accumulate(a,a+n,0ll);
	csm=0;
	// CCCCPPPP (C)
	for(int i=0;i<n;++i){
		csm+=a[i];
		psm-=a[i];
		if(psm>csm)++res;
		if(i+1<n&&psm-a[n-1]>csm+a[n-1])++res;
		// CCCCP CP PPPPC
		if(i+3<n){
			// no C
			int l=0,r=(n-(i+2))/2;
			while(l<r){
				int m=(l+r)/2;
				int midx=2*m+i+2; // idx of CPPPP
				ll tc=csm+ssm[i+2]-ssm[midx+2];
				ll tp=ssm[i+1]-ssm[midx+3];
				tp+=ssm[midx+2]+ssm[midx+3];
				if(tc<tp)l=m+1;
				else r=m;
			}
			res+=l;
			// C at the end
			if(i+4<n){
				int l=0,r=(n-(i+2)-1)/2;
				while(l<r){
					int m=(l+r)/2;
					int midx=2*m+i+2; // idx of CPPPP
					ll tc=csm+ssm[i+2]-ssm[midx+2];
					ll tp=ssm[i+1]-ssm[midx+3];
					tp+=ssm[midx+2]+ssm[midx+3];
					if(tc+a[n-1]<tp-a[n-1])l=m+1;
					else r=m;
				}
				res+=l;
			}
		}
	}
	res%=mod;
}

ll solve2(){
	ll res=0;
	// 0 == c
	for(int i=0;i<1<<n;++i){
		ll csm=0,psm=0;
		int dp=1e9,dc=0;
		int lp=-1,lc=-1;
		int j=0;
		for(j=0;j<n;++j){
			if(1<<(n-j-1)&i){
				if(~lp&&j-lp>dp)break;
				if(~lp)dp=j-lp;
				lp=j;
				psm+=a[j];
			}
			else{
				if(~lc&&j-lc<dc)break;
				if(~lc)dc=j-lc;
				lc=j;
				csm+=a[j];
			}
		}
//		if(j==n&&csm<psm)cerr<<bitset<5>(i)<<endl;
		res+=j==n&&csm<psm;
	}
	return res%mod;
}

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		res=0;
		memset(ssm,0,sizeof(*ssm)*(n+100));
		memset(a,0,sizeof(*a)*(n+100));
		for(int i=0;i<n;++i)cin>>a[i];
		solve();
		cout<<res<<"\n";
	}
//	for(n=200000;n>=0;--n){
//		int MX=1000000000;
//		for(int i=0;i<n;++i)a[i]=rand()%MX+1;
//	//	for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
//		solve();
//		ll sl=sol();
//		cerr<<res<<" "<<sl<<"\n";
//		assert(res==sl);
//	}
}