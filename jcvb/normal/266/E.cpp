#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
int n;
int ans[6];
int seg[300000][6],tag[300000];
int S[100005][6];
void pu(int rt){
	for (int i=0;i<=5;i++){
		seg[rt][i]=seg[rt<<1][i]+seg[rt<<1|1][i];
		if(seg[rt][i]>=mo)seg[rt][i]-=mo;
	}
}
void build(int l,int r,int rt){
	tag[rt]=-1;
	if(l==r){
		int x;scanf("%d",&x);
		seg[rt][0]=x;
		for (int i=1;i<=5;i++)seg[rt][i]=1ll*seg[rt][i-1]*l%mo;
	}else{
		int mid=l+r>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		pu(rt);
	}
}
int su(int n,int k){
	if(k==0)return n;
	if(k==1)return 1ll*n*(n+1)/2%mo;
	if(k==2)return 1ll*n*(n+1)*(2*n+1)/6%mo;
	if(k==3){
		int t=1ll*n*(n+1)/2%mo;
		return 1ll*t*t%mo;
	}
	if(k==4)return (1ll*n*(n+1)*(2*n+1)%mo)*((3ll*n*n+3*n-1)%mo)%mo*233333335%mo;	
	if(k==5)return 1ll*(n*(n+1ll)%mo)*(n*(n+1ll)%mo)%mo*(2ll*n*n%mo+2*n-1)%mo*83333334%mo;
}
int l1,r1,v;
void cov(int rt,int x,int l,int r){
	tag[rt]=x;
	for (int i=0;i<=5;i++){
		seg[rt][i]=S[r][i]-S[l-1][i];
		if(seg[rt][i]<0)seg[rt][i]+=mo;
		seg[rt][i]=1ll*seg[rt][i]*x%mo;
	}
}
void pd(int rt,int l,int r){
	if(~tag[rt]){
		cov(rt<<1,tag[rt],l,l+r>>1);
		cov(rt<<1|1,tag[rt],(l+r>>1)+1,r);
		tag[rt]=-1;
	}
}
void que(int l,int r,int rt){
	if(l1<=l && r<=r1){
		for (int i=0;i<=5;i++){
			ans[i]+=seg[rt][i];
			if(ans[i]>=mo)ans[i]-=mo;
		}
	}else{
		pd(rt,l,r);
		int mid=l+r>>1;
		if(l1<=mid)que(l,mid,rt<<1);
		if(r1>mid)que(mid+1,r,rt<<1|1);
	}
}
void upd(int l,int r,int rt){
	if(l1<=l && r<=r1){
		cov(rt,v,l,r);
	}else{
		pd(rt,l,r);
		int mid=l+r>>1;
		if(l1<=mid)upd(l,mid,rt<<1);
		if(r1>mid)upd(mid+1,r,rt<<1|1);
		pu(rt);
	}
}
int c[6][6];
int main()
{
    c[0][0]=1;
    for (int i=1;i<=5;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
	int q;scanf("%d%d",&n,&q);
    for (int i=0;i<=5;i++)
        for (int j=0;j<=n;j++)S[j][i]=su(j,i);
	build(1,n,1);
	while(q--){
		char c;while((c=getchar())!='=' && c!='?');
		int t;
		scanf("%d%d%d",&l1,&r1,&t);
		if(c=='='){
			v=t;
			upd(1,n,1);
		}else{
			memset(ans,0,sizeof(ans));
			que(1,n,1);
			int su=0;
			for (int j=0,sg=1;j<=t;j++){
                su=(su+1ll*ans[t-j]*sg%mo*::c[t][j])%mo;
                sg=1ll*sg*(1-l1)%mo;
            }
            su=(su+mo)%mo;
            printf("%d\n",su);
        }
   }
   return 0;
}