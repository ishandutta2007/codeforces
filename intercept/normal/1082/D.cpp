#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int M=509;
int n,sum=0,ans=0,cnt=0;
int a[M];
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
bool bol=0;
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i]==1)sum++;
		else ans+=a[i]-2,cnt++;
	}
	if(sum>ans+2)printf("NO");
	else {
		printf("YES %d\n",cnt+min(sum,2)-1);
		printf("%d\n",n-1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j||sum<=2)continue;
				if(a[i]==1&&a[j]>2){
					printf("%d %d\n",i,j);
					a[j]--;
					a[i]--;
					sum--;
				}
			}
		}
		int last=0,now=0,ls=0,rs=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1&&!ls)ls=i;
			if(a[i]==1&&!rs&&i!=ls)rs=i;
		}
		for(int i=1;i<=n;++i){
			if(a[i]>=2){
				now=i;
				if(last!=0)printf("%d %d\n",last,now);
				else if(ls)printf("%d %d\n",ls,now);
				last=now;
			}
		}
		if(rs)printf("%d %d\n",now,rs);
	}
	return 0;
}