#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t,n,ans;
int l,r,rv;
int k,p[N*3];
char a[N],b[N];
int power(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int get(int x){
	if(l<=r)return l+x-1;
	else return l-x+1;
}
int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	fo(i,1,t){
		scanf("%d\n",&n);
		scanf("%s\n%s",a+1,b+1);
		fo(i,1,n)a[i]-='0',b[i]-='0';
		l=1;r=n;rv=0;k=0;
		fd(i,1,n)
			if(a[get(i)]^rv!=b[i]){
				if(a[get(1)]^rv!=b[i])p[++k]=i;
				else p[++k]=1,a[get(1)]^=1,p[++k]=i;
				int pos=get(i);
				r=l;l=pos;rv^=1;
			}
		printf("%d ",k);fo(i,1,k)printf("%d ",p[i]);
		printf("\n");
	}
}