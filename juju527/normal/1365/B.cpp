#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int a[maxn],b[maxn];
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
		for(int i=1;i<=n;i++)a[i]=read();
		bool flag1=0,flag2=0;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1]){flag1=1;break;}
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=2;i<=n;i++)
			if(b[i]!=b[i-1]){flag2=1;break;}
		if(flag1&&flag2==0)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}