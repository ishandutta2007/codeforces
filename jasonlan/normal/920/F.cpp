#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int maxn=301000,maxai=1000100;
int n,m;
int pri[maxn],tnt;
int d[maxai],pcd[maxai];
int rt,ver,son[2][maxn<<1];
bool stable[maxn<<1];
ll sum[maxn<<1];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void reset(){
	d[1]=1;
	for(register int i=2;i<maxai;++i){
		if(!d[i]){
			d[i]=pcd[i]=2;pri[++tnt]=i; 
		}
		for(register int j=1,k;(k=i*pri[j])<maxai;++j){
			if(i%pri[j]==0){
				d[k]=d[i]/pcd[i]*(pcd[i]+1);
				pcd[k]=pcd[i]+1;
				break;
			}
			d[k]=d[i]*2;
			pcd[k]=2;
		}
	}
}
void update(int p){
	sum[p]=sum[son[0][p]]+sum[son[1][p]];
	stable[p]=stable[son[0][p]]&stable[son[1][p]];
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		sum[p]=read();
		stable[p]=d[sum[p]]==sum[p];
		return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,int l,int r){
	if(stable[p]||lr>r||l>rr)return;
	if(l==r){
		sum[p]=d[sum[p]];
		stable[p]=d[sum[p]]==sum[p];
		return;
	}
	modify(son[0][p],lr,rr,l,mid);
	modify(son[1][p],lr,rr,mid+1,r);
	update(p);
}
ll query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr)return sum[p];
	if(lr>r||l>rr)return 0ll;
	return query(son[0][p],lr,rr,l,mid)+query(son[1][p],lr,rr,mid+1,r); 
}
int main(){
	n=read();m=read();
	reset();
	build(rt,1,n);
	for(register int i=0,op,l,r;i<m;++i){
		op=read();l=read();r=read();
		if(op==1)
			modify(rt,l,r,1,n);
		else
			printf("%lld\n",query(rt,l,r,1,n));
	}
	return 0;
}