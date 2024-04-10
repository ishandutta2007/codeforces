#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n,k,l;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int rev[M];
void dft(vector<int>&A,int o){
	int lim=A.size(),inv3=kpow(3,mod-2);
	for(int i=0;i<lim;++i)if(rev[i]>i)swap(A[i],A[rev[i]]);
	for(int k=1;k<lim;k<<=1){
		int wn=kpow((o?3:inv3),(mod-1)/(k<<1));
		for(int i=0;i<lim;i+=k<<1){
			for(int j=0,w=1;j<k;++j,w=1ll*w*wn%mod){
				int x=A[i+j],y=1ll*w*A[i+j+k]%mod;
				A[i+j]=(x+y)%mod;
				A[i+j+k]=(x-y+mod)%mod;
			}
		}
	}
}
vector<int> mul(const vector<int>a,const vector<int>b){
	int len=a.size()+b.size()-1,l=__lg(len-1)+1;
	len=1<<l;
	for(int i=0;i<len;++i)rev[i]=(rev[i>>1]>>1)|(i&1)<<(l-1);
	vector<int> A(a),B(b);
	A.resize(len);
	B.resize(len);
	dft(A,1);
	dft(B,1);
	for(int i=0;i<len;++i)A[i]=1ll*A[i]*B[i]%mod;
	dft(A,0);
	int rex=kpow(len,mod-2);
	for(int i=0;i<len;++i)A[i]=1ll*A[i]*rex%mod;
	return A;
}
int main(){
	cin>>n>>k>>l;
	vector<int>a;
	a.resize(k+1);
	for(int i=0;i<=k;++i)a[i]=1;
	for(int i=1;i<=n;++i){
		vector<int>b,c,d;
		b.resize(k+1);
		b[k]=a[k];
		for(int j=k-1;j>=0;--j)b[j]=(b[j+1]+a[j])%mod;
		c=d=mul(a,a);
		if(i==n){
			if(l>k+k)puts("0");
			else cout<<d[l]<<endl;
			break;
		}
		for(int j=2*k-1;j>=0;--j)c[j]=(c[j]+c[j+1])%mod;
		for(int j=0;j<=k;++j){
			a[j]=(c[j]+1ll*d[j]*(k-j)%mod)%mod;
		}
	}
	return 0;
}
/*
1
??????
*/