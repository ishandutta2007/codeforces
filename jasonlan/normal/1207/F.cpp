#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=710;
int q,x,y,num[501000];
ll sum[maxn][maxn],ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	q=read();
	while(q--){
		if(read()==1){
			x=read();y=read();
			for(register int i=1;i<maxn;++i)
				sum[i][x%i]+=y;
			num[x]+=y;
		}
		else{
			x=read();y=read();
			if(x<maxn)
				printf("%lld\n",sum[x][y]);
			else{
				ans=0;
				for(register int i=y;i<=500000;i+=x)
					ans+=num[i];
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}