#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

#define N 270009

int LL, ll;

char s[N];
int mm,o[30],f[N][30],n,m,l,r,fl,ans;

int main()
{
	n=read();
	scanf("%s",s+1);
	mm=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=26;++j)f[i][j]=f[i-1][j];
		++f[i][s[i]-96];
	}
	while(mm--) {
		scanf("%s",s+1);
		ll=strlen(s+1);
		memset(o,0,sizeof(o));
		for(int i=1;i<=ll;++i)++o[s[i]-96];
		l=1; r=n;
		while(l<=r){
			m=(l+r)>>1;
			fl=0;
			for(int i=1;i<=26;++i)if(o[i]>f[m][i]){
				fl=1;
				break;
			}
			if(fl)l=m+1; else {
				ans=m; r=m-1;//int bool  // int bool;
			}
		}
		printf("%d\n",ans);
	}
}