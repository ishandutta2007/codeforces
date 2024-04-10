#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
void gn(int &x){
	char c;while((c=getchar())<'0'||c>'9');x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}

int n,m,k,q;
struct pkt{
	int x,y;
}p[200005];
int cmp(const pkt&a,const pkt&b){
	return a.x<b.x;
}
struct pyt{
	int x1,x2,y1,y2;
	int id;
}que[200005];
int cmp2(const pyt&a,const pyt&b){
	return a.x2<b.x2;
}
int ans1[200005],ans2[200005];

#define inf 1000000000
int seg[600000];
int v;
int l1,r1;
void qu(int l,int r,int x){
	if(l1<=l && r<=r1)v=min(v,seg[x]);
	else {
		int mid=l+r>>1;
		if(l1<=mid)qu(l,mid,x<<1);
		if(r1>mid)qu(mid+1,r,x<<1|1);
	}
}
int I;
void upd(int l,int r,int x){
	if(l==r)seg[x]=v;
	else{
		int mid=l+r>>1;
		if(I<=mid)upd(l,mid,x<<1);
		else upd(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
void work(int *ans){
	memset(seg,0,sizeof(seg));
	sort(p+1,p+1+k,cmp);
	sort(que+1,que+1+q,cmp2);
	for (int i=1,cur=1;i<=q;i++){
		while(cur<=k && p[cur].x<=que[i].x2){
			I=p[cur].y;
			v=p[cur].x;
			upd(1,m,1);
			cur++;
		}
		v=inf;l1=que[i].y1,r1=que[i].y2;
		qu(1,m,1);
		ans[que[i].id]=(v>=que[i].x1);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=k;i++){
		gn(p[i].x),gn(p[i].y);
	}
	for (int i=1;i<=q;i++){
		gn(que[i].x1);
		gn(que[i].y1);
		gn(que[i].x2);
		gn(que[i].y2);
		que[i].id=i;
	}
	work(ans1);
	for (int i=1;i<=k;i++)swap(p[i].x,p[i].y);
	for (int i=1;i<=q;i++){
		swap(que[i].x1,que[i].y1);
		swap(que[i].x2,que[i].y2);
	}
	swap(n,m);
	work(ans2);
	for (int i=1;i<=q;i++)if(ans1[i]||ans2[i])printf("YES\n");else printf("NO\n");
	return 0;
}