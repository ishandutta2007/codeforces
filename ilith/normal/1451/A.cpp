#include <bits/stdc++.h>
using namespace std;inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;read(As...);}
template <typename T> inline void write(T a){if(a<0ll)putchar('-'),a=-a;if(a>9ll)write(a/10ll);putchar(a%10ll+'0');}
int t,n; 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=3)cout<<n-1;
		else if(n&1){
			cout<<3;
		}
		else cout<<2;
		cout<<'\n';
	}
	return 0;
}