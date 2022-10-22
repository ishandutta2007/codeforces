#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
int n,p,k;
int a[N],b[N];
priority_queue<int,vector<int>,greater<int>>pq;
typedef long long ll;
int id[N];
ll prv[N],suf[N];
int main(){
//	srand((unsigned long long)(new char));
//	n=rand()%20+1;p=rand()%n+1;k=rand()%p+1;
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0;i<n;++i){
//		a[i]=rand();b[i]=rand();
		scanf("%d%d",a+i,b+i);
		id[i]=i;
	}
//	printf("%d %d %d\n",n,p,k);
//	for(int i=0;i<n;++i)printf("%d %d\n",a[i],b[i]);
	sort(id,id+n,[&](int x,int y){
		return b[x]==b[y]?a[x]<a[y]:b[x]>b[y];
	});
	ll cur;
	cur=0;
	for(int ii=0;ii<n-p+k;++ii){
		int i=id[ii];
		pq.push(a[i]);cur+=a[i];
		if(pq.size()>k){cur-=pq.top();pq.pop();}
		prv[ii]=cur;
	}
	while(!pq.empty())pq.pop();
	cur=0;
	for(int ii=n-1;ii>=k;--ii){
		int i=id[ii];
		pq.push(b[i]);cur+=b[i];
		if(pq.size()>p-k){cur-=pq.top();pq.pop();}
		suf[ii-1]=cur;
	}
	ll ansx=-0x3f3f3f3f,ansy=-0x3f3f3f3f,ansi;
	for(int i=0;i<n-p+k;++i){
		if(prv[i]>ansx||(prv[i]==ansx&&suf[i]>ansy)){
			ansi=i;ansx=prv[i];ansy=suf[i];
		}
	}
	sort(id,id+ansi+1,[&](int x,int y){
		return a[x]>a[y];
	});
	sort(id+ansi+1,id+n,[&](int x,int y){
		return b[x]>b[y];
	});
	for(int i=0;i<k;++i)printf("%d ",id[i]+1);
	for(int i=ansi+1;i<=ansi+p-k;++i)printf("%d",id[i]+1),putchar(i==ansi+p-k?'\n':' ');
	return 0;
}