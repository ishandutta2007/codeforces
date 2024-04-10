#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e6+9;
const int mod=998244353;
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
int n,x,y;
int d[M];
int q;
int ans[M];
vector<int>p[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>y;
	for(int i=0;i<=n;++i){
		cin>>d[i];
	}
	vector<int>a,b,c;
	a.resize(x+1);
	b.resize(x+1);
	for(int i=0;i<=n;++i){
		a[d[i]]=1;
		b[x-d[i]]=1;
	}
	c=mul(a,b);
	for(int i=0;i<=n;++i)c[d+x-d]--;
	memset(ans,-1,sizeof(ans));
	for(int i=max(4,y*2);i<M;i+=2){
		if(x+i/2-y<c.size()&&c[x+i/2-y])ans[i]=i;
		for(int j=i;j<M;j+=i)ans[j]=max(ans[j],ans[i]);
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int l;
		cin>>l;
		cout<<ans[l]<<" \n"[i==q];
	}
	return 0;
}
/*
1 10 5
0 10
1
10

*/