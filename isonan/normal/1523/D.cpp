#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

int n,m,p;
long long s[200001];
int stk[21],top;
char str[101];
int cnt[1048576],lim;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i){
		scanf("%s",str);
		s[i]=0;
		for(int j=0;j<m;++j)s[i]|=(1ll*(str[j]=='1'))<<j;
	}
	int ans=0;
	long long fin=0;
	for(int i=1;i<=20;++i){
		int u=(1ll*rand()*rand())%n+1;
		top=0;
		for(int j=0;j<m;++j)
			if(s[u]&(1ull<<j))stk[++top]=j;
		lim=1<<top;
		memset(cnt,0,lim<<2);
		for(int j=1;j<=n;++j){
			int stat=0;
			for(int k=1;k<=top;++k)
				if(s[j]&(1ull<<stk[k]))stat|=1<<(k-1);
			++cnt[stat];
		}
		for(int i=1;i<lim;i<<=1)
			for(int j=0;j<lim;j+=(i<<1))
				for(int k=0;k<i;++k)
					cnt[j+k]+=cnt[i+j+k];
		for(int i=0;i<lim;++i)if(cnt[i]>=((n+1)>>1)){
			int x=__builtin_popcount(i);
			if(ans<x){
				ans=x;
				fin=0;
				for(int j=1;j<=top;++j)
					if(i&(1ull<<(j-1)))fin|=1ull<<stk[j];
			}
		}
	}
	for(int i=0;i<m;++i)
		if(fin&(1ull<<i))putchar('1');
		else putchar('0');
}