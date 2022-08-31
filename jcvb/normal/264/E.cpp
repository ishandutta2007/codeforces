#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define inf 1000000000
using namespace std;
int n,m;
struct seg{
	int a[600000];
	int n;
	int I,l1,r1,v;
	int ans;
	int cv;
	void _upd(int l,int r,int x){
		if(l==r){
			if(!cv)a[x]=v;
			else a[x]=max(a[x],v);
		}
		else{
			int mid=l+r>>1;
			if(I<=mid)_upd(l,mid,x<<1);
			else _upd(mid+1,r,x<<1|1);
			a[x]=max(a[x<<1],a[x<<1|1]);
		}
	}
	void _que(int l,int r,int x){
		if(l1<=l && r<=r1)ans=max(ans,a[x]);
		else{
			int mid=l+r>>1;
			if(l1<=mid)_que(l,mid,x<<1);
			if(r1>mid)_que(mid+1,r,x<<1|1);
		}
	}
	void chg(int i,int x){
		I=i,v=x;cv=0;
		_upd(1,n,1);
	}
	void cov(int i,int x){
		I=i,v=x;cv=1;
		_upd(1,n,1);
	}
	int que(int l,int r){
		l1=l,r1=r,ans=0;
		if(l<=r)_que(1,n,1);
		return ans;
	}
	int lis[15],tot;
	void _find(int l,int r,int x){
		if(a[x]==0)return;
		if(l==r)lis[++tot]=l;
		else{
			int mid=l+r>>1;
			if(l1<=mid)_find(l,mid,x<<1);
			if(r1>mid)_find(mid+1,r,x<<1|1);
		}
	}
	int find(int ma){
		l1=1,r1=ma,tot=0;
		_find(1,n,1);
		return tot;
	}
	int lef;
	void _find2(int l,int r,int x){
		if(a[x]==0||!lef)return;
		if(l==r)lis[++tot]=l,lef--;
		else{
			int mid=l+r>>1;
			_find2(l,mid,x<<1);
			_find2(mid+1,r,x<<1|1);
		}
	}
	void find2(int c){
		tot=0,lef=c;
		_find2(1,n,1);
	}
}segi,segw;
int w[210000]={0},id[210000]={0};
int seq[15],tot;
int seq2[15],tot2;
int tmpl[15];
int main()
{
	scanf("%d%d",&n,&m);
	segi.n=n;
	segw.n=m+10;
	while(m--){
		int ot;scanf("%d",&ot);
		if(ot==1){
			int i,h;scanf("%d%d",&i,&h);
			h+=m;
			int num=segw.find(h);
			tot=tot2=0;
			for (int s=1;s<=num;s++){
				int tmp=id[segw.lis[s]];
				if(tmp<i)seq[++tot]=tmp;
				else seq2[++tot2]=tmp;
			}
			sort(seq+1,seq+1+tot);
			sort(seq2+1,seq2+1+tot2);
			int ma=0;
			if(!tot2)ma=segi.que(i,n);
			else{
				ma=max(ma,segi.que(i,seq2[1]-1));
				ma=max(ma,segi.que(seq2[tot2]+1,segi.n));
				for (int j=1;j<tot2;j++)
					ma=max(ma,segi.que(seq2[j]+1,seq2[j+1]-1));
			}
			w[i]=h;
			id[h]=i;
			seq[++tot]=i;tmpl[tot]=ma+1;
			for (int i=tot-1;i>=1;i--){
				ma=0;
				for (int j=i+1;j<=tot;j++)if(w[seq[i]]<w[seq[j]])ma=max(ma,tmpl[j]);
				tmpl[i]=ma+1;
			}
			for (int i=1;i<=tot;i++){
				segi.cov(seq[i],tmpl[i]);
				segw.cov(w[seq[i]],tmpl[i]);
			}
		}else if(ot==2){
			int x;scanf("%d",&x);
			segi.find2(x);
			for (int i=1;i<=x;i++){
				int tmp=segi.lis[i];
				segi.chg(tmp,0);
				segw.chg(w[tmp],0);
			}
			for (int i=x-1;i>=1;i--){
				int tmp=segi.lis[i];
				int ma=segw.que(w[tmp]+1,segw.n);
				segw.cov(w[tmp],ma+1);
				segi.cov(tmp,ma+1);
			}
		}
		printf("%d\n",segi.a[1]);
	}
	return 0;
}