#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T& A){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;}template <typename T> inline void read(T& A,T& B){read(A),read(B);}template <typename T> inline void read(T& A,T& B,T& C){read(A),read(B),read(C);}
template <typename T> inline void write(T a){if(a<0)putchar('-'),a=-a;if(a>9)write(a/10);putchar(a%10+'0');}
long long t,p,q;
long long bk[100010];
long long prime[100010],cnt;
long long cntq,cntp;
long long ans;
inline long long qpow(long long a,long long b,long long mod){long long ans=1;a%=mod;while(b){if(b&1)ans=ans*a%mod;b>>=1,a=a*a%mod;}return ans;}
int main(){
	bk[1]=1;
	for(long long i=2;i<=100000;i++){
		if(!bk[i])prime[++cnt]=i;
		for(long long j=1;j<=cnt&&i*prime[j]<100000;j++){
			bk[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	read(t);
	while(t--){
		ans=1000000000000000000ll;
		bool notres=0;
		read(p,q);
		long long pp=p;
		for(long long i=1;prime[i]*prime[i]<=q;i++){
			cntp=cntq=0;
			while(q%prime[i]==0){
				q/=prime[i];
				cntq++;
			}
			if(cntq){
				while(p%prime[i]==0){
					p/=prime[i];
					cntp++;
				}
				if(cntp<cntq){
					write(pp);
					putchar('\n');
					goto tag;
				}
				if(cntp>=cntq){//restriction:cntq 
					ans=min(ans,qpow(prime[i],cntp-cntq+1,1000000000000000000ll));
				}
			}
		}
		if(q!=1){
			cntp=0;
			cntq=1;
			while(p%q==0){
				p/=q;
				cntp++;
			}
			if(cntp<cntq){
				write(pp);
				putchar('\n');
				goto tag;
			}
			if(cntp>=cntq){//restriction:q itself 
				ans=min(ans,qpow(q,cntp-cntq+1,1000000000000000000ll));
			}
		}
		write(pp/ans);
		putchar('\n');
		tag:;
	}
	return 0; 
}