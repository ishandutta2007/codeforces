#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
using namespace std;
const int N=1e5+5;
int n,k,A,B,a[N];
ll ans;
ll go(int l,int r,int x,int y){
	if(l>r)return A;
	ll tot=(ll)B*(r-l+1)*(y-x+1);
	if(x==y)return tot;
	int m=(ll)x+y>>1,w=r+1;
	fo(i,l,r)if(a[i]>m){
		w=i;
		break;
	}
	return min(tot,go(l,w-1,x,m)+go(w,r,m+1,y));
}
int main(){
	scanf("%d%d%d%d",&n,&k,&A,&B);
	fo(i,1,k)scanf("%d",&a[i]);
	sort(a+1,a+k+1);
	ans=go(1,k,1,1<<n);
	printf("%I64d",ans);
}