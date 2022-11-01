#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include <cassert>
#define N 200011
#define S 411
using namespace std;
int n,m;
int a[N];
int fa[N];
int va[N];
int fi[S][N];
int tag[N];
int maxx[N];
int pl[N];
int sz[N];
int ll[N];
int rr[N];
int ss;
int nn;
int tmp[N];
inline const int MIN(const int & a,const int &b){
	return a<b?a:b;
}
inline const int MAX(const int & a,const int &b){
	return a>b?a:b;
}
int find(int x){
//	if(de>1000000){
//		cout<<"oo";
//		exit(0);
//	}
	return fa[x]?(fa[x]=find(fa[x])):x;
}
int uni(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return x;
	}
	if(sz[x]<sz[y]){
		int tmp=x;
		x=y;
		y=tmp;
	}
	fa[y]=x;
	sz[x]+=sz[y];
	return x;
}
void init_(){//
	memset(ll,0x7f,sizeof(ll));
	for(int i=1;i<=n;i++){
		pl[i]=i/ss+1;
		ll[pl[i]]=MIN(ll[pl[i]],i);
		rr[pl[i]]=MAX(rr[pl[i]],i);
	}
	nn=pl[n];
	// for( int i = 1 ; i <= nn ; ++i )
	for(int i=1;i<=nn;i++){
		// cout << ll[i] << " " << rr[i] << endl;
		for(int j=ll[i];j<=rr[i];j++){
			va[j]=a[j];
			maxx[i]=MAX(maxx[i],a[j]);
			// cout << a[j] << endl;
			assert( a[j] != -1 );
			if(fi[i][a[j]]){
				sz[fi[i][a[j]]]++;
				fa[j]=fi[i][a[j]];
			}else{
				sz[j]=1;
				fi[i][a[j]]=j;
				fa[j]=0;
			}
		}
	}
	return ;
}
void change(int p,int x){//
	if(x*2<=(maxx[p]-tag[p])){//x
		for(int i=1;i<=x;i++){
			if(fi[p][i+tag[p]]){
				if(fi[p][i+tag[p]+x]){
					fi[p][i+tag[p]+x]=uni(fi[p][i+tag[p]+x],fi[p][i+tag[p]]);
				}else{
					fi[p][i+tag[p]+x]=fi[p][i+tag[p]];
				}
				va[fi[p][i+tag[p]+x]]=i+tag[p]+x;
			}
			fi[p][i+tag[p]]=0;
		}
		tag[p]+=x;
	}else if(x*2>(maxx[p]-tag[p])){
		for(int i=x+1;i<=maxx[p]-tag[p];i++){
			if(fi[p][i+tag[p]]){
				if(fi[p][i+tag[p]-x]){
					fi[p][i+tag[p]-x]=uni(fi[p][i+tag[p]-x],fi[p][i+tag[p]]);
				}else{
					fi[p][i+tag[p]-x]=fi[p][i+tag[p]];
				}
				va[fi[p][i+tag[p]-x]]=i+tag[p]-x;
			}
			fi[p][i+tag[p]]=0;
		}
		maxx[p]=MIN(maxx[p],tag[p]+x);
	}
	return ;
}
inline void out(int p){//a
	for(int i=ll[p];i<=rr[p];i++){
		a[i]=va[find(i)]-tag[p];
	}
	return ;
}
void rebuild(int p,int l,int r,int val){//
	out(p);
	tag[p]=0;
	maxx[p]=0;
	for(int i=l;i<=r;i++){
		if(a[i]>val){
			a[i]-=val;
		}
	}
	for(int i=ll[p];i<=rr[p];i++){
		maxx[p]=MAX(maxx[p],a[i]);
		fi[p][va[i]]=0;
	}
	for(int i=ll[p];i<=rr[p];i++){
		va[i]=a[i];
	}
	for(int i=ll[p];i<=rr[p];i++){
		if(fi[p][a[i]]){
			sz[fi[p][a[i]]]++;
			fa[i]=fi[p][a[i]];
		}else{
			sz[i]=1;
			fi[p][a[i]]=i;
			fa[i]=0;
		}
	}
	return ;
}
void change(int l,int r,int val){//
	if(pl[l]==pl[r]){
		rebuild(pl[l],l,r,val);
		return ;
	}
	rebuild(pl[l],l,rr[pl[l]],val);
	rebuild(pl[r],ll[pl[r]],r,val);
	for(int i=pl[l]+1;i<pl[r];i++){
		change(i,val);
	}
	return ;
}
int query(int l,int r,int val){//
	if(pl[l]==pl[r]){
		int ans=0;
		out(pl[l]);
		for(int i=l;i<=r;i++){
			if(a[i]==val){
				ans++;
			}
		}
		return ans;
	}
	int ans=0;
	out(pl[l]);
	out(pl[r]);
	for(int i=l;i<=rr[pl[l]];i++){
		if(a[i]==val){
			ans++;
		}
	}
	for(int i=ll[pl[r]];i<=r;i++){
		if(a[i]==val){
			ans++;
		}
	}
	for(int i=pl[l]+1;i<pl[r];i++){
		ans+=sz[fi[i][val+tag[i]]];
	}
	return ans;
}
int main(){
	#ifdef intLSY
	freopen("in.in","r",stdin);
	#endif
//	cout<<sizeof(fi)/1024/1024;
	cin>>n>>m;
	ss=MAX((int)sqrt(n),2);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init_();
	for(int i=1;i<=m;i++){
		int ord;
		scanf("%d",&ord);
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if(ord==1){
			change(l,r,x);
		}else if(ord==2){
			printf("%d\n",query(l,r,x));
		}
	}
	return 0;
}
/*
8 13
75 85 88 100 105 120 122 128
1 1 8 70
1 3 8 3
1 2 4 10
1 2 7 27
2 1 5 5

5 13
75 85 88 100 105


8 13
75 85 88 100 105 120 122 128
1 1 8 70
2 3 8 30
1 3 8 3
2 2 5 15
1 2 4 10
2 1 5 5
1 2 7 27
2 1 5 5
1 3 7 12
1 1 7 4
2 1 8 1
1 4 8 5
2 1 8 1
*/