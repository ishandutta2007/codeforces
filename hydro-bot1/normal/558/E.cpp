// Hydro submission #61daa3b853a171eeac3567c0@1641718713002
#include<bits/stdc++.h>
#define mid (l+r>>1)
#define lid id,p<<1,l,mid
#define rid id,p<<1|1,mid+1,r
#define seg int id,int p,int l,int r
using namespace std;
const int N=1e5+5;
struct segtree{int sum,id,la;}tr[27][N<<2];
int s[30],n,m,ans[N];
char st[N];
void pd(seg){
	if(tr[id][p].la==1){
		tr[id][p<<1].sum=mid-l+1;tr[id][p<<1].la=1;
		tr[id][p<<1|1].sum=r-mid;tr[id][p<<1|1].la=1;
	}
	else{
		tr[id][p<<1].sum=0;tr[id][p<<1].la=-1;
		tr[id][p<<1|1].sum=0;tr[id][p<<1|1].la=-1;
	}
	tr[id][p].la=0;
}
void add(seg,int L,int R){
	if(L>R)return;
	if(l>=L&&r<=R){
		tr[id][p].sum=(r-l+1);
		tr[id][p].la=1;
		return;
	}
	if(tr[id][p].la)pd(id,p,l,r);
	if(L<=mid)add(lid,L,R);
	if(R>mid)add(rid,L,R);
	tr[id][p].sum=tr[id][p<<1].sum+tr[id][p<<1|1].sum;
}
int ask(seg,int L,int R){
	if(l>=L&&r<=R)return tr[id][p].sum;
	if(tr[id][p].la)pd(id,p,l,r);
	return (L<=mid?ask(lid,L,R):0)+(R>mid?ask(rid,L,R):0);
}
void clear(seg,int L,int R){
    if(l>=L&&r<=R){tr[id][p].sum=0;tr[id][p].la=-1;return;}
    if(tr[id][p].la)pd(id,p,l,r);
    if(L<=mid)clear(lid,L,R);
	if(R>mid)clear(rid,L,R);
	tr[id][p].sum=tr[id][p<<1].sum+tr[id][p<<1|1].sum;
}
void write(seg){
	if(!tr[id][p].sum)return;
	if(l==r){ans[l]=id;return;}
	if(tr[id][p].la)pd(id,p,l,r);
	write(lid),write(rid);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)add(st[i]-'a',1,1,n,i,i);
	for(int i=1;i<=m;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		for(int j=0;j<26;j++)s[j]=ask(j,1,1,n,l,r),clear(j,1,1,n,l,r);
		int x=l;
		if(k==0)k--;
		for(int j=(k>0?0:25);k>0?(j<26):j>=0;j+=k){
			add(j,1,1,n,x,x+s[j]-1);
			x+=s[j];
		}
	}
	for(int i=0;i<=25;i++)write(i,1,1,n);
	for(int i=1;i<=n;i++)putchar('a'+ans[i]);
}