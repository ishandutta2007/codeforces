#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=3e6+9;
int n,t;
int b[M],cnt[M];
int rev[M];
vector<vector<int>>p;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
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
vector<int> mul(const vector<int>&a,const vector<int>&b){
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
vector<int> solve(int l,int r){
	if(l==r)return p[l];
	int mid=(l+r)>>1;
	return mul(solve(l,mid),solve(mid+1,r));
}
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		b[x]++;
	}
	for(int i=2;i<M;++i)cnt[b[i]]++;
	for(int i=1;i<=n;++i){
		if(cnt[i]==0)continue;
		vector<int>t;
		for(int j=0;j<=i;++j)t.eb(1);
		int len=(i+1)*cnt[i],l=__lg(len-1)+1;
		len=1<<l;
		for(int k=0;k<len;++k)rev[k]=(rev[k>>1]>>1)|(k&1)<<(l-1);
		t.resize(len);
		dft(t,1);
		for(int k=0;k<len;++k)t[k]=kpow(t[k],cnt[i]);
		dft(t,0);
		int rex=kpow(len,mod-2);
		for(int k=0;k<len;++k)t[k]=1ll*t[k]*rex%mod;
		p.eb(t);
	}
	random_shuffle(p.begin(),p.end());
	auto a=solve(0,p.size()-1);
	cout<<a[n/2]<<"\n";
	return 0;
}
/*
4 1
1 2 3
*/