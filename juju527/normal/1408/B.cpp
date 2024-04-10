#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int a[maxn];
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
		int n,k;
		n=read();k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(k==1){
			bool flag=0;
			for(int i=2;i<=n;i++)if(a[i]^a[i-1]){flag=1;break;}
			if(flag){printf("-1\n");continue;}
			printf("1\n");continue;
		}
		a[0]=-1;
		int c=0,m=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				c++;
				if(c==k+1){c=2;m++;}
			}
		}
		printf("%d\n",m);
	}
	return 0;
}