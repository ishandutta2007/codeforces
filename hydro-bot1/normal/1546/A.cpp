// Hydro submission #614c884a9fed8bb91a24d3a2@1632406364243
#include <bits/stdc++.h>
using namespace std;
const int N=110;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int t,n;
int a[N],b[N];
int sa,sb;
int dis[N];
int main(){
	t=read();
	while(t--){
		n=read();
		sa=sb=0;
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			b[i]=read();
		for(int i=1;i<=n;i++)	
			sa+=a[i];
		for(int i=1;i<=n;i++)
			sb+=b[i];
		if(sa!=sb){
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			dis[i]=b[i]-a[i];
		for(int i=1;i<=n;i++)
			ans+=(dis[i]>0?dis[i]:0);
		printf("%d\n",ans);
		while(ans--){
			for(int i=1;i<=n;i++){
				if(dis[i]>=0) continue;
				printf("%d ",i);
				dis[i]++;
				for(int j=1;j<=n;j++){
					if(dis[j]>0){
						printf("%d\n",j);
						dis[j]--;
						break;
					}
				}
				break;
			}
		}
	}
	return 0;
}