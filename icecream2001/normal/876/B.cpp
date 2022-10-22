#include<iostream>
#include<cstdio>
using namespace std;
inline int Read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,m,x,now,ans,js;
int a[200000],b[200000];
int main(){
	while(scanf("%d%d%d",&n,&k,&m)!=EOF){
		ans=0;
		for(int i=0;i<m;i++) a[i]=0;
		for(int i=1;i<=n;i++){
			b[i]=Read();
			now=b[i]-(b[i]/m)*m;
			a[now]++;
			if(a[now]>a[ans]) ans=now;
		}
		if(a[ans]>=k){
			printf("Yes\n");js=k;
			for(int i=1;i<=n;i++){
				if(!js) break;
				if(b[i]%m==ans){js--;printf("%d ",b[i]);}
			}
			printf("\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}