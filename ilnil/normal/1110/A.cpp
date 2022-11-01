#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e5+5,mo=1e9+7;
int b,k,cnt,a;
int main(){
	scanf("%d%d",&b,&k);
	fo(i,1,k)scanf("%d",&a),cnt+=((i==k||b%2==1)&&(a%2==1));
	if(cnt&1)printf("odd");else printf("even");
	
}