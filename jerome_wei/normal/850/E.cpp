#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char x=0;while(x<'0'||x>'9')x=getchar();
	return x-'0';
}
/* read */
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
const int inv2=qpow(2,mod-2);
/* math */
const int N=1.5e6+5;
int A[N],B[N],n,len;
inline void FWT_xor(int *t,int n,int type){
	for(int step=1;step<n;step<<=1)
		for(int i=0;i<n;i+=step<<1)
			for(int j=0;j<step;j++){
				int x=t[i+j],y=t[i+j+step];
				t[i+j]=add(x,y),t[i+j+step]=sub(x,y);
				if(type==-1)t[i+j]=mul(t[i+j],inv2),t[i+j+step]=mul(t[i+j+step],inv2);
			}
}

int main()
{
	scanf("%d",&n);
	len=1<<n;
	for(int i=0;i<1<<n;i++){
		A[i]=read();B[i]=A[i]^1;
	}

	FWT_xor(A,len,1); FWT_xor(B,len,1);
	for(int i=0;i<len;i++)A[i]=mul(A[i],B[i]);
	FWT_xor(A,len,-1);
	
	int ans=0;
	for(int i=0;i<len;i++){
		int Q=__builtin_popcount(i);
		//cout<<Q<<" ";
		ans=add(ans,mul(1<<Q,A[i]));
	}
//	puts("");
//	for(int i=0;i<len;i++)cout<<A[i]<<" ";puts("");
//	for(int i=0;i<len;i++)cout<<C[i]<<" ";puts("");
	printf("%d\n",mul(ans,3));/* (?) */
}