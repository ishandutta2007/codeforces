#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=105;
int n,ans,f[N][N][2];
struct no{int p,l;}a[N];
bool cmp(no x,no y){return x.p<y.p;}
int main(){
	cin>>n;
	fo(i,1,n)cin>>a[i].p>>a[i].l;
	sort(a+1,a+n+1,cmp);
	a[0].p=-1e9;
	fo(i,0,n)fo(j,0,n)fo(k,0,1){
		ans=max(ans,f[i][j][k]);
		int mx=a[j].p+k*a[j].l,mx2=-1e9,x,y;
		fo(l,i+1,n)fo(p,0,1){
			int mx3=a[l].p+p*a[l].l;
			if(mx3>mx2)mx2=mx3,x=l,y=p;
			f[l][x][y]=max(f[l][x][y],f[i][j][k]+min(a[l].l,mx3-mx)+mx2-mx3);
		}
	}
	cout<<ans;
}