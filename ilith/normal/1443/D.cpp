#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T& A){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;}
template <typename T> inline void read(T& A,T& B){read(A),read(B);}
template <typename T> inline void read(T& A,T& B,T& C){read(A),read(B),read(C);}
template <typename T> inline void write(T a){if(a<0)putchar('-'),a=-a;if(a>9)write(a/10);putchar(a%10+'0');}
long long t;
long long n;
long long a[30010];
int main(){
	read(t);
	while(t--){
		read(n);
		long long nowmin=999999999,nowdelmax=0;
		for(long long i=1;i<=n;i++){
			read(a[i]);
			nowmin=min(nowmin,max(a[i]-nowdelmax,0ll));
			a[i]-=nowmin;
			nowdelmax=max(nowdelmax,a[i]);
			a[i]-=nowdelmax;
		}
		for(long long i=1;i<=n;i++){
			if(a[i]){
				puts("NO");
				goto tag;
			}
		}
		puts("YES");
		tag:;
	}
	return 0;
}