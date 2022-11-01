#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,a[N],b[N],bz;
int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	fo(i,1,n)scanf("%d",&b[i]);
	if(a[1]==b[1]){
		fo(i,1,n-1)a[i]=a[i+1]-a[i],b[i]=b[i+1]-b[i];
		sort(a+1,a+n);sort(b+1,b+n);
		fo(i,1,n-1)if(a[i]!=b[i]){
			bz=1;break;
		}
	}else bz=1;
	if(bz)printf("No");else printf("Yes");
}