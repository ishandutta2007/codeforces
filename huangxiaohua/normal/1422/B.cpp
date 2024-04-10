#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,i,j,t;
ll a[105][105],b[5],res;
void chk(int i,int j){
	int i1=i,j1=j,i2=n+1-i,j2=m+1-j;
	if((i1==i2)&&(j1==j2)){return;}
	if((i1==i2)&&(j1!=j2)){res+=abs(a[i1][j1]-a[i1][j2]);return;}
	if((i1!=i2)&&(j1==j2)){res+=abs(a[i1][j1]-a[i2][j1]);return;}
	b[1]=a[i1][j1];b[2]=a[i2][j1];b[3]=a[i1][j2];b[4]=a[i2][j2];
	sort(b+1,b+5);
	res+=b[4]-b[2]+b[3]-b[2]+b[2]-b[1];
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);res=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=(n+1)/2;i++){
			for(j=1;j<=(m+1)/2;j++){
				chk(i,j);
			}
		}
		printf("%lld\n",res);
	}
}