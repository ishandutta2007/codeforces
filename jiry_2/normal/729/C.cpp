#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[210000],d[210000];
int n,K,s,t;
struct atom{
	int w,c;
	void scan(){
		scanf("%d%d",&w,&c);
	}
}A[210000];
int compare(atom k1,atom k2){
	return k1.c<k2.c;
}
int check(int lim){
	int tot=0;
	for (int i=1;i<=K;i++){
		if (lim<d[i]) return 0;
		tot+=max(1ll*d[i],3ll*d[i]-lim);
	}
	//cout<<lim<<" "<<tot<<endl;
	return (tot<=t);
}
int main(){
	scanf("%d%d%d%d",&n,&K,&s,&t);
	for (int i=1;i<=n;i++) A[i].scan();
	for (int i=1;i<=K;i++) scanf("%d",&a[i]);
	sort(a+1,a+K+1);
	for (int i=1;i<=K;i++) d[i]=a[i]-a[i-1];
	K++; d[K]=s-a[K-1];
	sort(A+1,A+n+1,compare);
	int l=1,r=n+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(A[mid].c)){
			r=mid; ans=mid;
		} else l=mid+1;
	}
	if (ans==0){
		printf("-1\n"); return 0;
	}
	int num=2e9;
	for (int i=ans;i<=n;i++) num=min(num,A[i].w);
	printf("%d\n",num);
}