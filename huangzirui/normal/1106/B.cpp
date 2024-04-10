#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
int i,j,k,n,m;
int s[maxn],w[maxn],now,nowx;
int x,y;
ll sum,ans;
struct node{
	int w,b;
}mi[maxn];
bool cmp(node x,node y){
	return x.w<y.w||(x.w==y.w&&x.b<y.b);
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++){scanf("%d",&w[i]);mi[i].w=w[i];mi[i].b=i;}
	sort(mi+1,mi+1+n,cmp);
	now=1;
	for(i=1;i<=m;i++){
		ans=0;
		scanf("%d%d",&x,&y);
		sum=min(y,s[x]);
		s[x]-=sum;
		y-=sum;
		ans+=sum*w[x];
		while(y){
			if(now==n+1)break;
			nowx=mi[now].b;
			sum=min(y,s[nowx]);
			s[nowx]-=sum;
			y-=sum;
			ans+=sum*w[nowx];
			if(!s[nowx])++now;
		}
		if(!y)
			printf("%I64d\n",ans);
		else printf("0\n");
	}
	return 0;
}