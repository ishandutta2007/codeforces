#include <bits/stdc++.h>
using namespace std;inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;read(As...);}
template <typename T> inline void write(T a){if(a<0ll)putchar('-'),a=-a;if(a>9ll)write(a/10ll);putchar(a%10ll+'0');}
int t,n,q;
char s[1000010];
int l0,l1,f0,f1;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>q>>s+1;
		l0=l1=f0=f1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				if(!f0){
					f0=i;
				}
				l0=i;
			}
			if(s[i]=='1'){
				if(!f1){
					f1=i;
				}
				l1=i;
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			if(s[x]=='0'){
				if(f0!=x){
					puts("YES");
					continue;
				}
			}
			else{
				if(f1!=x){
					puts("YES");
					continue;
				}
			}
			
			if(s[y]=='0'){
				if(l0!=y){
					puts("YES");
					continue;
				}
			}
			else{
				if(l1!=y){
					puts("YES");
					continue;
				}
			}
			
			puts("NO");
		}
	}
	return 0;
}