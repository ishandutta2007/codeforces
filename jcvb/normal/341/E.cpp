#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int a[1005];
int li[1005];

int u[1000005],v[1000005],le=0;
void move(int i,int j){
	a[i]-=a[j];
	a[j]*=2;
	u[++le]=j,v[le]=i;
}
void work(int i,int j,int k){
	if(a[i]>a[j])swap(i,j);
	if(a[j]>a[k])swap(j,k);
	if(a[i]>a[j])swap(i,j);
	if(a[i]==a[j]){
		move(i,j);
		return;
	}
	if(a[j]==a[k]){
		move(j,k);
		return;
	}
	int t=a[j]/a[i];
	for (int x=1;x<=t;x<<=1){
		if(t&x)move(j,i);
		else move(k,i);
	}
}	
int main()
{
	scanf("%d",&n);
	int su=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i])li[++su]=i;
	}
	if(su<=1){
		printf("-1\n");
		return 0;
	}
	for (int i=su-2;i>=1;i--){
		work(li[i],li[i+1],li[i+2]);
		if(!a[li[i+1]])swap(li[i+1],li[i+2]);
		else if(!a[li[i]])swap(li[i],li[i+2]);
		else if(!a[li[i+2]]);
		else i++;
	}
	printf("%d\n",le);
	for (int i=1;i<=le;i++)printf("%d %d\n",u[i],v[i]);
	return 0;
}