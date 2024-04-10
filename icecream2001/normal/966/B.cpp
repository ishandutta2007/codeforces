#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL long long
#define N 300050 
using namespace std;
int n;
LL x,y;
int mx[N];
LL s[N];
struct date{
	int id;
	LL c;
}p[N];
bool cmp(date a,date b){return a.c<b.c;}
int main(){
	scanf("%d%I64d%I64d",&n,&x,&y);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&p[i].c);
		p[i].id=i;
	}
	sort(p+1,p+1+n,cmp);
	int t=n,f;
	for(int i=n;i>=1;--i){
		s[i]=(LL)(n-i+1)*p[i].c;
		if(s[t]<s[i]) t=i;mx[i]=t;
	}
	for(int i=1;i<n;++i){
		if(s[i]>=x){
			f=ceil(x*1.0/p[i].c)+i-1;
			if(f<n&&s[f+1]>=y){
				printf("Yes\n");
				printf("%d %d\n",f-i+1,n-f);
				for(int j=i;j<f;++j) printf("%d ",p[j].id);printf("%d\n",p[f].id);
				for(int j=f+1;j<n;++j) printf("%d ",p[j].id);printf("%d\n",p[n].id);
				return 0;
			}
		}
		if(s[i]>=y){
			f=ceil(y*1.0/p[i].c)+i-1;
			if(f<n&&s[f+1]>=x){
				printf("Yes\n");
				printf("%d %d\n",n-f,f-i+1);
				for(int j=f+1;j<n;++j) printf("%d ",p[j].id);printf("%d\n",p[n].id);
				for(int j=i;j<f;++j) printf("%d ",p[j].id);printf("%d\n",p[f].id);
				return 0;
			}
		}
	}
	printf("No\n");
	return 0; 
}