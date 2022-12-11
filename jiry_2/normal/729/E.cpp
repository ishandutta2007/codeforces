#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s,num,ans,now,rem1,rem2;
int x[210000],y[210000];
int main(){
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	if (x[s]!=0) x[s]=0,now=1;
	for (int i=1;i<=n;i++)
		if (i!=s&&x[i]==0){
			num++;
		}
	for (int i=1;i<=n;i++) y[x[i]]++;
	num=n-1; rem1=0;
	int ans=num;
	for (int i=1;i<=n;i++){
		num-=y[i];
		if (y[i]==0) rem1++;
		ans=min(ans,max(rem1,num));
	}
	printf("%d\n",ans+now);
	return 0;
}