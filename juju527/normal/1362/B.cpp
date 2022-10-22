#include<bits/stdc++.h>
using namespace std;
const int maxn=1024;
int s[maxn];
int st[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n;
		n=read();
		for(int i=1;i<=n;i++){
			s[i]=read();
			st[s[i]]=1;
		}
		int ans=1024;
		for(int i=2;i<=n;i++){
			bool flag=0;
			int k=s[1]^s[i];
			for(int j=2;j<=n;j++)
				if(!st[s[j]^k]){flag=1;break;}
			if(!flag)ans=min(ans,k);
		}
		for(int i=1;i<=n;i++)st[s[i]]=0;
		if(ans==1024)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}