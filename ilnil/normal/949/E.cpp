#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
#define abs(x)(x>0?x:-(x))
using namespace std;
const int N=1e5+5;
int n,a[25][N],k,an[30],kk,ans[30];
void calc(int x,int r,int A){
	bool bz=0;
	if(k>=kk)return;
	fo(i,1,r)if(a[x][i]&1){bz=1;break;}
	if(r==1&&abs(a[x][1])==1||r==2&&a[x][1]==-1&&!a[x][2]){
		an[++k]=a[x][1]*A;
		calc(x+1,0,A);k--;
		return;
	}
	if(!r){
		kk=k;memcpy(ans,an,sizeof an);
		return;
	}
	if(bz){
		int rr=r;
		fo(i,1,rr)a[x+1][i]=a[x][i]-(a[x][i]&1)>>1;
		an[++k]=A;r=unique(a[x+1],a[x+1]+rr+1)-a[x+1]-1;
		calc(x+1,r,A<<1);
		fo(i,1,rr)a[x+1][i]=a[x][i]+(a[x][i]&1)>>1;
		an[k]=-A;r=unique(a[x+1],a[x+1]+rr+1)-a[x+1]-1;
		calc(x+1,r,A<<1);k--;
		return;
	}
	fo(i,1,r)a[x+1][i]=a[x][i]>>1;
	r=unique(a[x+1],a[x+1]+r+1)-a[x+1]-1;
	calc(x+1,r,A<<1);
	return;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[0][i]);
	sort(a[0]+1,a[0]+n+1);
	n=unique(a[0]+1,a[0]+n+1)-a[0]-1;
	kk=1e9;calc(0,n,1);
	printf("%d\n",kk);
	fo(i,1,kk)printf("%d ",ans[i]);
}