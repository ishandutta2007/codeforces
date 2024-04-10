#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N],la[N],nw;
int v[N],fr[N],mx,wz;
vector<int>va[N];
bool bz[N];
int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&m);
	fo(i,1,m)scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	fo(i,1,n)if(a[i]==-1){
		la[i]=nw;
		int k=m+1;
		fd(j,0,mx){
			for(;k>1&&b[k-1]>v[j];)--k;
			if(k<=m){
				if(mx==j){
					++mx,wz=i;
					v[j+1]=b[k],fr[j+1]=i;
				}else
				if(b[k]<v[j+1])v[j+1]=b[k],fr[j+1]=i;
			}
		}
		nw=i;
	}else{
		int le=lower_bound(v+1,v+mx+1,a[i])-v;
		la[i]=fr[le-1];
		v[le]=a[i];fr[le]=i;
		va[le].push_back(i);
		if(le>mx)mx=le,wz=i;
	}
	int i=m,las=1e9+5;
	for(;mx;--mx)
		if(a[wz]==-1){
			for(;b[i]>=las;)--i;
			a[wz]=b[i];las=a[wz];bz[i]=1;
			int le=lower_bound(va[mx-1].begin(),va[mx-1].end(),wz)-va[mx-1].begin()-1;
			if(le<0||a[va[mx-1][le]]>=a[wz]){
				wz=la[wz];
				continue;
			}
			wz=va[mx-1][le];
		}else las=a[wz],wz=la[wz];
	i=0;
	fo(j,1,n){
		if(a[j]==-1){
			for(;++i,bz[i];);
			a[j]=b[i];
		}
		printf("%d ",a[j]);
	}
}