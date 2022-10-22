#include<bits/stdc++.h>
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
int n,ans;
char a[N],b[N];
int s1[N],s2[N],s3[N];
signed main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	for(rgi i=1;i<=n;++i){
		s3[b[i]-'A']++;
		s2[a[i]-'A']++;
	}
	for(rgi i=1;i<=n;++i){
		int ch=a[i]-'A';
		if(s2[ch]>s3[ch]){
			for(rgi j=0;j<ch;++j){
				if(s2[j]<s3[j]){
					a[i]=j+'A';
					++ans;
					s2[ch]--;
					s2[j]++;
					break;
				}
			}
		}
		ch=a[i]-'A';
		if(s1[ch]>=s3[ch]){
			for(rgi j=0;j<26;++j){
				if(s2[j]<s3[j]){
					a[i]=j+'A';
					++ans;
					s2[ch]--;
					s2[j]++;
					break;
				}
			}
		}
		s1[a[i]-'A']++;
	}
	printf("%d\n%s\n",ans,a+1);
	return 0;
}