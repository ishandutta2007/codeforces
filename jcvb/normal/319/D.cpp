#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define seed 10007ll
using namespace std;
typedef long long ll;
int n;
char s[50005];
ll h[50005],pp[50005];
void build(){
	h[0]=0;
	for (int i=1;i<=n;i++)h[i]=h[i-1]*seed+s[i];
}
int cmp(int i,int j,int l){
	return h[i+l-1]-h[j+l-1]==(h[i-1]-h[j-1])*pp[l];
}
int lcp(int i,int j){
	int l=1,r=n-max(i,j)+1,m;
	while(l<=r){
		m=l+r>>1;
		if(cmp(i,j,m))l=m+1;
		else r=m-1;
	}
	return r;
}
int lcs(int i,int j){
	int l=1,r=min(i,j),m;
	while(l<=r){
		m=l+r>>1;
		if(cmp(i-m+1,j-m+1,m))l=m+1;
		else r=m-1;
	}
	return r;
}
int qu[50005],p=0,q=0;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	pp[0]=1;for (int i=1;i<=n;i++)pp[i]=pp[i-1]*seed;
	build();
	for (int len=1;len*2<=n;len++){
		int rig=0;
		for (int i=1,j=1+len;j<=n;i+=len,j+=len){
			int l=lcs(i,j),r=lcp(i,j);
			if(i-l<rig)l=i-rig;
			if(l+r-1>=len){
				qu[q++]=i-l+1;
				rig=qu[q-1]+len-1;
			}
		}
		if(p!=q){
			int j=0;
			for (int i=1;i<=n;i++){
				if(qu[p]==i){
					i+=len-1;
					p++;
				}else s[++j]=s[i];
			}
			n=j;
			build();
		}
	}
	for (int i=1;i<=n;i++)putchar(s[i]);putchar('\n');
	return 0;
}