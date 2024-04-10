#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int n,m,B,cnt;
int a[N],b[N],g[N],c[N],L[N],R[N];
int find(int x){
	int l=1,r=cnt,mid;
	while(1){
		mid=l+r>>1;
		if(b[mid]==x) return mid;
		else if(b[mid]<x) l=mid+1;
		else r=mid-1;
	}
}
int F[2010][2010];
int pos[N];
vector<int> v[N];
int main(){
	n=read();m=read();B=sqrt(n);
	for(int i=1;i<=n;++i) {
		a[i]=read();
		b[i]=a[i];
		g[i]=(i+B-1)/B;
	}
	for(int i=1;i<=g[n];++i){
		L[i]=(i-1)*B+1;
		R[i]=min(i*B,n);
	}
	sort(b+1,b+1+n);
	cnt=1;
	for(register int i=2;i<=n;++i) 
		if(b[i]!=b[i-1]) b[++cnt]=b[i];
	for(register int i=1;i<=n;++i) a[i]=find(a[i]);
	int mx;
	for(int i=1;i<g[n];++i){
		mx=0;
		for(int j=i;j<g[n];++j){
			for(int k=L[j];k<=R[j];++k){
				++c[a[k]];
				if(c[a[k]]>mx) mx=c[a[k]];
			}
			F[i][j]=mx;
		}
		for(int j=i;j<g[n];++j)
			for(int k=L[j];k<=R[j];++k)
				--c[a[k]];
	}
	for(int i=1;i<=n;++i){
		pos[i]=c[a[i]];
		++c[a[i]];
		v[a[i]].push_back(i);
	}
	int ans=0,l,r;
	for(int tt=1;tt<=m;++tt){
		l=read();r=read();
		ans=F[g[l]+1][g[r]-1];
		for(int i=l;i<=R[g[l]];++i){
			for(;pos[i]+ans<v[a[i]].size();++ans)
				if(v[a[i]][pos[i]+ans]>r) break;
		}
		for(int i=L[g[r]];i<=r;++i){
			for(;pos[i]-ans>=0;++ans)
				if(v[a[i]][pos[i]-ans]<l) break;
		}
		print(max(0,ans+ans-2-r+l)+1);puts("");
	}
	return 0;
}
/*

*/