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
char str[1100005];

int n,m=3;
int s[2100005];
int tmp1[2100005],tmp2[2100005],cnt[2100005],sa[2100005],*rank;
void doubling(){
	int *x=tmp1,*y=tmp2,num,i,j,len;
	for (i=0;i<m;i++)cnt[i]=0;
	for (i=0;i<n;i++)cnt[s[i]]++;
	for (i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for (i=n-1;i>=0;i--)sa[--cnt[s[i]]]=i;
	for (num=i=1,x[sa[0]]=0;i<n;i++)x[sa[i]]=s[sa[i]]==s[sa[i-1]]?num-1:num++;
	for (len=1;num<n;len<<=1){
		for (j=0;j<len;j++)y[j]=n-len+j;
		for (i=0;i<n;i++)if(sa[i]>=len)y[j++]=sa[i]-len;
		
		for (i=0;i<num;i++)cnt[i]=0;//num
		for (i=0;i<n;i++)cnt[x[i]]++;
		for (i=1;i<num;i++)cnt[i]+=cnt[i-1];
		for (i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
		
		swap(x,y);
		for (num=i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?num-1:num++;
	}
	rank=x;
}


inline int cmp(int i,int j){
	return rank[i-1]<rank[j-1];
}
int seg[4444444],tag[4444444];
int pr[2444444]={0};

void init(int l,int r,int x){
	if(l==r){
		seg[x]=pr[l];
	}else{
		int mid=l+r>>1;
		init(l,mid,x<<1);
		init(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
int l1,r1,v;

inline void pd(int x){
	seg[x<<1]+=tag[x];
	tag[x<<1]+=tag[x];
	tag[x<<1|1]+=tag[x];
	seg[x<<1|1]+=tag[x];
	tag[x]=0;
}
void upd(int l,int r,int x){
	if(l1<=l && r<=r1){
		seg[x]+=v;
		tag[x]+=v;
	}else{
		int mid=l+r>>1;
		if(tag[x])pd(x);
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
void que(int l,int r,int x){
	if(l1<=l && r<=r1){
		v=min(v,seg[x]);
	}else{
		int mid=l+r>>1;
		if(tag[x])pd(x);
		if(l1<=mid)que(l,mid,x<<1);
		if(r1>mid)que(mid+1,r,x<<1|1);
	}
}
int main()
{
	int N;
	scanf("%s",str+1);
	N=strlen(str+1);
	for (int i=1;i<=N;i++){
		if(str[i]=='(')s[i-1]=s[i-1+N]=1;
		else s[i-1]=s[i-1+N]=2;
	}
	n=N*2+1;
	s[n-1]=0;
	pr[0]=0;
	doubling();
	for (int i=1;i<=N;i++)
		pr[i]=pr[i-1]+(str[i]=='('?1:-1);
	for (int i=N+1;i<=2*N;i++)pr[i]=pr[N];
	init(1,2*N,1);
#define inf 1000000000
	int ma=-inf;int id;
	for (int st=1;st<=N;st++){
		v=0;
		l1=st,r1=st+N-1;
		que(1,2*N,1);
		if(v>ma){
			ma=v;
			id=st;
		}else if(v==ma && cmp(st,id)){
			id=st;
		}
		v=str[st]=='('?-1:1;
		upd(1,2*N,1);
	}
	for (int i=1;i<=-ma;i++)putchar('(');
	for (int i=id;i<=N;i++)putchar(str[i]);
	for (int i=1;i<id;i++)putchar(str[i]);
	int xxx=pr[N]+(-ma);
	for (int i=1;i<=xxx;i++)putchar(')');
	putchar('\n');
	return 0;
}