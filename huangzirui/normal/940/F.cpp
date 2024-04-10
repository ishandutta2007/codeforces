#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,N;
int a[maxn];
int S[maxn],ans,block[maxn],Sta[maxn],is[maxn],top,mex[maxn],cnt;
struct query{
	int l,r,id,time;
	bool operator< (query &x)const{
		return block[l]==block[x.l]? (block[r]==block[x.r]? time<x.time:r<x.r):l<x.l;
	}
}Q[maxn];
inline void del(int x){
	mex[S[a[x]]]--;
	S[a[x]]--;
	mex[S[a[x]]]++;
}
inline void insert(int x){
	mex[S[a[x]]]--;
	S[a[x]]++;
	mex[S[a[x]]]++;
}
int Ans[maxn],chk[maxn][2];
void modify(int i,int X){
	int tp=chk[X][0],L=Q[i].l,R=Q[i].r;
	if(L<=tp && tp<=R){
		del(tp);
		swap(a[tp],chk[X][1]);
		insert(tp);
	}else swap(a[tp],chk[X][1]);
}
int Sum[maxn*2],Cnt;
void make(int &x){
	int l=1,r=Cnt;
	while(r>=l){
		int Mid=l+r>>1;
		if(x==Sum[Mid]){
			x=Mid;return;
		}
		if(x<Sum[Mid])r=Mid-1;
		else l=Mid+1;
	}
}
int main(){
	cin>>n;N=pow(n,0.6666);cin>>m;
	for(i=1;i<=n;i++)scanf("%d",&a[i]),Sum[++Cnt]=a[i];
	for(i=1;i<=n;i++)block[i]=(i-1)/N+1;
	for(i=1;i<=m;i++){
		int op;scanf("%d",&op);
		if(op==1){
			++cnt;
			scanf("%d%d",&Q[cnt].l,&Q[cnt].r);
			Q[cnt].id=cnt;Q[cnt].time=k;
		}else{
			k++;
			scanf("%d%d",&chk[k][0],&chk[k][1]);
			Sum[++Cnt]=chk[k][1];
		}
	}
	sort(Sum+1,Sum+1+Cnt);
	for(i=1;i<=n;i++)make(a[i]);
	for(i=1;i<=k;i++)make(chk[i][1]);
	sort(Q+1,Q+1+cnt);
	int l=1,r=0,now=0;
	for(i=1;i<=cnt;i++){
		int L=Q[i].l,R=Q[i].r,Time=Q[i].time;
		while(r<R){
			r++;
			insert(r);
		}
		while(L<l){
			l--;
			insert(l);
		}
		while(l<L){
			del(l);
			l++;
		}
		while(R<r){
			del(r);
			r--;
		}
		while(now<Time){
			now++;
			modify(i,now);
		}
		while(now>Time){
			modify(i,now);
			now--;
		}
		int ans=0;
		for(j=1;;j++)if(!mex[j]){ans=j;break;}
		Ans[Q[i].id]=ans;
	}
	for(i=1;i<=cnt;i++)printf("%d\n",Ans[i]);
	return 0;
}