#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
int n,m,i,j,k,id,aa[N],bb[N],a[N],b[N],ida[N],idb[N],kk[N],ans[N];
ll c[N],mn=1ll<<60,sb[N];
int TP;
inline void add(int l,int r,int v){//
	if(TP==0)l-=i,r-=i;else swap(l,r),l=i-l,r=i-r;//TP==0 -> i
	l=(l+n)%n;r=(r+n)%n;
	if(l<=r)c[l]+=v,c[r+1]-=v;else c[l]+=v,c[n]-=v,c[0]+=v,c[r+1]-=v;
//	printf("%d %d %d\n",l,r,v);
}
bool cmpa(int x,int y){return aa[x]<aa[y];}
bool cmpb(int x,int y){return bb[x]<bb[y];}
//a b
inline void work1(int*a,int*b,int z){
	for(i=1,j=k=0;i<=n && b[i]<=m/2;++i){
		for(;j<n && (TP?a[j+1]<b[i]:a[j+1]<=b[i]);++j);
		for(;k<n && a[k+1]<=b[i]+m/2;++k);
		if(j)add(1,j,b[i]);
		if(j+1<=k)add(j+1,k,-b[i]);
		if(k<n)add(k+1,n,b[i]+z);
	}
//puts("fdsa");
}
inline void work2(int*a,int*b,int z){
	for(i=1;i<=n && b[i]<=m/2;++i);
	for(j=k=0;i<=n;++i){
		for(;j<n && a[j+1]<b[i]-m/2;++j);
		for(;k<n && (TP?a[k+1]<b[i]:a[k+1]<=b[i]);++k);
		if(j)add(1,j,-b[i]+z);
		if(j+1<=k)add(j+1,k,b[i]);
		if(k<n)add(k+1,n,-b[i]);
	}
//puts("fdsafdsa");
}
inline void bf(){
	for(int i=0;i<n;++i){
		ll s=0;
		for(int j=1;j<=n;++j){
			int k=j+i,d;
			if(k>n)k-=n;
			d=abs(a[k]-b[j]);
			s+=min(d,m-d);
		}
		assert(c[i]==s);
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)scanf("%d",aa+i);
	for(i=1;i<=n;++i)scanf("%d",bb+i);
/*
	srand(time(0));
	for(i=1;i<=n;++i)aa[i]=rand()%m+1;
	for(i=1;i<=n;++i)bb[i]=rand()%m+1;
*/
	for(i=1;i<=n;++i)ida[i]=idb[i]=i;
	sort(ida+1,ida+n+1,cmpa);
	sort(idb+1,idb+n+1,cmpb);
	for(i=1;i<=n;++i)a[i]=aa[ida[i]],b[i]=bb[idb[i]],sb[i]=sb[i-1]+b[i];
	TP=1;
	work1(b,a,m);
	TP=0;
	work1(a,b,0);
	TP=1;
	work2(b,a,m);
	TP=0;
	work2(a,b,0);
	for(i=0;i<n;++i){
		if(i)c[i]+=c[i-1];
		if(c[i]<mn)mn=c[i],id=i;		
	}
//	bf();
	for(i=1;i<=n;++i)ans[ida[i+id-(i+id>n?n:0)]]=idb[i];
	cout<<mn<<'\n';
	for(i=1;i<=n;++i)printf("%d ",ans[i]);puts("");		
	return 0;
}