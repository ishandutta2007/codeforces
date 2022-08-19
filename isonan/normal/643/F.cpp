#include <cstdio>

typedef unsigned ul;
ul n,p,q;
struct matrix{
	ul num[131][131];
	matrix operator*(const matrix &a){
		static matrix c;
		for(int i=0;i<=p;i++)
			for(int j=0;j<=p;j++){
				c.num[i][j]=0;
				for(int k=0;k<=p;k++)
					c.num[i][j]+=num[i][k]*a.num[k][j];
			}
		return c;
	}
}unit,mat[131];
struct vector{
	ul num[131];
	vector operator*(const matrix &a){
		static vector c;
		for(int i=0;i<=p;i++){
			c.num[i]=0;
			for(int j=0;j<=p;j++)c.num[i]+=num[j]*a.num[j][i];
		}
		return c;
	}
}vec[20001];
ul vis[131];
ul gcd(ul a,ul b){return (!b)?a:gcd(b,a%b);}
ul C(ul n,ul m){
	if(n<0)return 0;
	ul ans=1;
	for(ul i=1;i<=m;i++)vis[i]=i;
	for(ul i=0;i<m;i++){
		ul tem=n-i;
		for(int j=m;j;j--){
			ul _gcd=gcd(tem,vis[j]);
			vis[j]/=_gcd;
			tem/=_gcd;
		}
		ans*=tem;
	}
	return ans;
}
int main(){
	scanf("%u%u%u",&n,&p,&q);
	if(p>n-1)p=n-1;
	for(int i=0;i<=p;i++)
		for(int j=0;i+j<=p;j++)
			unit.num[i][i+j]=C(n-(p-i-j),j);
	for(int i=0;i<=p;i++)vec[0].num[i]=1;
	for(int i=1;i<16384;i++)vec[i]=vec[i-1]*unit;
	for(int i=0;i<=p;i++)mat[0].num[i][i]=1;
	for(int i=1;i<=14;i++)unit=unit*unit;
	for(int i=1;i<=(q>>14);i++)mat[i]=mat[i-1]*unit;
	ul ans=0;
	for(ul i=1;i<=q;i++){
		ul A=i>>14,B=i&16383;
		ul tem=0;
		for(ul j=0;j<=p;j++)tem+=vec[B].num[j]*mat[A].num[j][p];
		ans^=tem*i;
	}
	printf("%u",ans);
}