#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,k,x[510],y[510],s[1100][1100];
int cntx,numx[1100],cnty,numy[1100];
bool check(int t){
	//x[i]-t..x[i]+t
	//y[i]-t..y[i]+t
	cntx=0; cnty=0;
	numx[++cntx]=1; numx[++cntx]=n+1;
	numy[++cnty]=1; numy[++cnty]=m+1;
	for (int i=1;i<=k;i++){
		numx[++cntx]=max(1,x[i]-t); numx[++cntx]=min(n+1,x[i]+t+1);
		numy[++cnty]=max(1,y[i]-t); numy[++cnty]=min(m+1,y[i]+t+1);
	}
	sort(numx+1,numx+cntx+1); cntx=unique(numx+1,numx+cntx+1)-numx-1;
	sort(numy+1,numy+cnty+1); cnty=unique(numy+1,numy+cnty+1)-numy-1;
	for (int i=1;i<=cntx;i++)
		for (int j=1;j<=cnty;j++)
			s[i][j]=0;
	for (int i=1;i<=k;i++){
		int txl=lower_bound(numx+1,numx+cntx+1,max(1,x[i]-t))-numx;
		int txr=lower_bound(numx+1,numx+cntx+1,min(n+1,x[i]+t+1))-numx;
		int tyl=lower_bound(numy+1,numy+cnty+1,max(1,y[i]-t))-numy;
		int tyr=lower_bound(numy+1,numy+cnty+1,min(m+1,y[i]+t+1))-numy;
		s[txl][tyl]++; s[txl][tyr]--;
		s[txr][tyl]--; s[txr][tyr]++;
	}
	int xl=INF,xr=0,yl=INF,yr=0;
	for (int i=1;i<cntx;i++)
		for (int j=1;j<cnty;j++){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if (!s[i][j]){
				xl=min(xl,i); xr=max(xr,i);
				yl=min(yl,j); yr=max(yr,j);
			}
		}
	if (xl==INF) return true;
	xl=numx[xl]; xr=numx[xr+1]-1;
	yl=numy[yl]; yr=numy[yr+1]-1;
	return (xl+t>=xr-t)&&(yl+t>=yr-t);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d%d",&x[i],&y[i]);
	int l=0,r=1e9+1,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}