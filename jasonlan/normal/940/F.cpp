#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=201000;
int n,m;
int col[maxn];
int cnt[2],ans[maxn],cntcol,mex[maxn];
int pos[maxn],tnt[maxn<<1],rnk[maxn<<1],dr;
struct que{
	int x,y,z,d;
}note[2][maxn];
	bool cmp(que q,que a){
		if(pos[q.x]!=pos[a.x])
			return pos[q.x]<pos[a.x];
		else if(pos[q.y]!=pos[a.y])
			return pos[q.y]<pos[a.y];
		else return q.z<a.z;
	}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void swapg(int &a,int &b){
	int c=a;a=b;b=c;
}
void add(int p){
	--mex[tnt[p]];++tnt[p];++mex[tnt[p]];
	if(!mex[tnt[p]-1]&&tnt[p]-1)
		cntcol=min(cntcol,tnt[p]-1);
	while(mex[cntcol])++cntcol;
}
void del(int p){
	--mex[tnt[p]];--tnt[p];++mex[tnt[p]];
	if(!mex[tnt[p]+1])
		cntcol=min(cntcol,tnt[p]+1);
	while(mex[cntcol])++cntcol;
}
void modify(int t,int l,int r){
	if(l<=note[0][t].x&&note[0][t].x<=r){
		del(col[note[0][t].x]);
		add(note[0][t].y);
	}
	swapg(col[note[0][t].x],note[0][t].y);
}
int main(){
	n=read();m=read();
	int t=pow(n,(double)2/(double)3);
	for(register int i=1;i<=n;++i){
		col[i]=read(),pos[i]=(i-1)/t+1;
		rnk[++dr]=col[i];
	}
	for(register int i=1,j=0;i<=m;++i){
		bool g=read()&1;
		if(g){
			note[1][++cnt[1]].x=read();
			note[1][cnt[1]].y=read();
			note[1][cnt[1]].z=cnt[0];
			note[1][cnt[1]].d=cnt[1];
		}
		else{
			note[0][++cnt[0]].x=read();
			note[0][cnt[0]].y=read();
			rnk[++dr]=note[0][cnt[0]].y;
		}
	}
	sort(rnk+1,rnk+dr+1);
	dr=unique(rnk+1,rnk+dr+1)-rnk-1;
	for(register int i=1;i<=n;++i)
		col[i]=lower_bound(rnk+1,rnk+dr+1,col[i])-rnk;
	for(register int i=1;i<=cnt[0];++i)
		note[0][i].y=lower_bound(rnk+1,rnk+dr+1,note[0][i].y)-rnk;
	mex[0]=dr;
	sort(note[1]+1,note[1]+cnt[1]+1,cmp);
	cntcol=1;
	for(register int i=1,t=0,l=1,r=0;i<=cnt[1];++i){
		while(t<note[1][i].z)++t,modify(t,l,r);
		while(t>note[1][i].z)modify(t,l,r),--t;
		while(r<note[1][i].y)++r,add(col[r]);
		while(l<note[1][i].x)del(col[l]),++l;
		while(l>note[1][i].x)--l,add(col[l]);
		while(r>note[1][i].y)del(col[r]),--r;
		ans[note[1][i].d]=cntcol;
	}
	for(register int i=1;i<=cnt[1];++i)
		printf("%d\n",ans[i]);
	return 0;
}