#include <bits/stdc++.h>

int n,a,b;
double v[2][2001],ans,fin,f[2001][2001];
void upd(double &a,const double &b){if(a<b)a=b;}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int j=0;j<2;j++)
		for(int i=1;i<=n;i++)
			scanf("%lf",&v[j][i]);
	for(int i=1;i<=n;i++){
		double v1=v[0][i],v2=v[1][i],v3=v1+v2-v1*v2;
		for(int j=std::min(a,i);~j&&j+n-i>=a;--j)
			for(int k=std::min(b,i);~k&&k+n-i>=b;--k){
				double &p=f[j][k];
				if(j)upd(p,f[j-1][k]+v1);
				if(k)upd(p,f[j][k-1]+v2);
				if(j&&k)upd(p,f[j-1][k-1]+v3);
			}
	}
	printf("%.6lf\n",f[a][b]);
}