#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=210;
int n,k,ans;
char s[maxn],sa,sb;
int f[2][maxn][maxn],cnt;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline char getch(){
	char ch=getchar();
	while(ch>'z'||ch<'a')ch=getchar();
	return ch;
}
void reset(bool t){
	for(register int i=0;i<=k;++i)
		for(register int j=0;j<=n;++j)
			f[t][i][j]=-0x3f3f3f3f;
}
int main()
{
	n=read();k=read();
	for(register int i=1;i<=n;++i)
		s[i]=getch();
	sa=getch();sb=getch();
	bool t=false;
	reset(t);
	f[t][0][0]=0;
	for(register int i=1;i<=n;++i){
		t^=1;
		reset(t);
		for(register int j=0;j<=k;++j){
			//
			for(register int a=0;a<=n;++a){
				//
				if(f[t^1][j][a]<0)continue;
				//
				if(s[i]==sa){
					if(sa==sb)
						f[t][j][a+1]=max(f[t][j][a+1],f[t^1][j][a]+a);
					else
						f[t][j][a+1]=max(f[t][j][a+1],f[t^1][j][a]);
				}
				else if(s[i]==sb)
					f[t][j][a]=max(f[t][j][a],f[t^1][j][a]+a);
				else
					f[t][j][a]=max(f[t][j][a],f[t^1][j][a]);
				if(j<k){
					// 
					if(sa==sb)
						f[t][j+1][a+1]=max(f[t][j+1][a+1],f[t^1][j][a]+a);
					else{
						//
						f[t][j+1][a+1]=max(f[t][j+1][a+1],f[t^1][j][a]);
						//
						f[t][j+1][a]=max(f[t][j+1][a],f[t^1][j][a]+a);
					}
				}
			}
		}
	}
	int ans=0;
	for(register int i=0;i<=k;++i)
		for(register int j=0;j<=n;++j)
			ans=max(ans,f[t][i][j]);
	printf("%d\n",ans);
	return 0;
}