#include <bits/stdc++.h>
using namespace std;inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;read(As...);}
template <typename T> inline void write(T a){if(a<0ll)putchar('-'),a=-a;if(a>9ll)write(a/10ll);putchar(a%10ll+'0');}
int t,n,k;
char s1[1000010],s2[1000010];
int cnta[30],cntb[30]; 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>s1+1>>s2+1;
		memset(cnta,0,sizeof cnta);
		memset(cntb,0,sizeof cntb);
		for(int i=1;i<=n;i++){
			cnta[s1[i]-'a']++;
			cntb[s2[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(cnta[i]>=cntb[i]){
				int c=cnta[i]-cntb[i];
				if(c%k!=0){
					puts("No");
					goto tag;
				}
				else{
					cnta[i]=cntb[i];
					cnta[i+1]+=c;
				}
			}
			else{
				puts("No");
				goto tag;
			}
		}
		puts("Yes");
		tag:;
	}
	return 0;
}