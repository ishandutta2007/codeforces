#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e6+5,mo=1e9+7;
int n,m,a,aa,bb,cnt[N],ans,f[2][7][7];
int g;
int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%d",&a),cnt[a]++;
	fo(i,0,4)fo(j,0,4)f[0][i][j]=-1;
	f[0][0][0]=0;int o=0;
	fo(i,1,m){
		o^=1;
		fo(j,0,4)fo(k,0,4)f[o][j][k]=-1;
		fo(j,0,4)fo(k,0,4)if(f[!o][j][k]>-1){
			aa=f[!o][j][k];
			fo(l,0,min(cnt[i],4)){
				int us=min(cnt[i]-l,min(j,k));
				f[o][k-us][l]=max(f[o][k-us][l],aa+(cnt[i]-us-l)/3+us);
			}
		}
	}
	fo(i,0,4)fo(j,0,4)ans=max(ans,f[o][i][j]);
	printf("%d",ans);
}