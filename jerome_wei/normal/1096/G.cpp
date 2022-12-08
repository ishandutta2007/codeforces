#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
typedef long long ll;
const int mod=998244353,g=3;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/

namespace Template_Poly{
	typedef vector<int> Poly;
	int rev[N];
	void DFT(int *t,int n,int type){
		int l=0;while(1<<l<n)++l;
		for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<n;i++)if(rev[i]>i)swap(t[rev[i]],t[i]);
		for(int step=1;step<n;step<<=1){
			int wn=qpow(g,(mod-1)/(step<<1));
			for(int i=0;i<n;i+=step<<1){
				int w=1;
				for(int k=0;k<step;k++,w=mul(w,wn)){
					int x=t[i+k],y=mul(t[i+k+step],w);
					t[i+k]=add(x,y),t[i+k+step]=sub(x,y);
				}
			}
		}
		if(type==1)return;
		for(int i=1;i<n-i;i++)swap(t[i],t[n-i]);
		int inv=qpow(n,mod-2);
		for(int i=0;i<n;i++)t[i]=mul(t[i],inv);
	}
	Poly NTT(Poly A,int n,Poly B,int m){
		static Poly res,PolA,PolB;
		PolA=A,PolB=B;
		int len=1;while(len < n+m)len<<=1;
		res.resize(len);
		PolA.resize(len),PolB.resize(len);
		DFT(&PolA[0],len,1);DFT(&PolB[0],len,1);
		for(int i=0;i<len;i++) res[i]= mul(PolA[i],PolB[i]);
		DFT(&res[0],len,-1);
		res.resize(n+m-1);
		return res;
	}
	Poly NTT(Poly A,Poly B){
		return NTT(A,A.size(),B,B.size());
	}
}
using namespace Template_Poly;
Poly A(10,0),ret(1,1);
int n,k;

int main()
{
	cin>>n>>k;
	n/=2;
	for(int i=1;i<=k;i++){
		int t;cin>>t;
		A[t]++;
	}
	for(;n;n>>=1,A=NTT(A,A))if(n&1){
		ret=NTT(A,ret);
	}
	int ans=0;
	for(size_t i=0;i<ret.size();i++){
		ans=add(ans,mul(ret[i],ret[i]));
	}
	cout<<ans<<endl;
}