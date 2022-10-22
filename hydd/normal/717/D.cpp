#include<stdio.h>
#include<string.h>
using namespace std;
const int Mod=30011;
int n,x; double p[128];
struct Matrix{
	double v[128][128];
	void init(){
		for (int i=0;i<=127;i++)
			for (int j=0;j<=127;j++)
				v[i][j]=p[i^j];
	}
	Matrix operator*(const Matrix &a) const{
		Matrix res;
		for (int i=0;i<=127;i++)
			for (int j=0;j<=127;j++)
				res.v[i][j]=0;
		for (int k=0;k<=127;k++)
			for (int i=0;i<=127;i++)
				if (v[i][k])
					for (int j=0;j<=127;j++)
						if (a.v[k][j])
							res.v[i][j]+=v[i][k]*a.v[k][j];
		return res;
	}
} A,B;
Matrix qpow(Matrix &x,int a){
	Matrix res;
	for (int i=0;i<=127;i++)
		for (int j=0;j<=127;j++)
			res.v[i][j]=(i==j);
	while (a){
		if (a&1) res=res*x;
		x=x*x; a>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&x);
	for (int i=0;i<=x;i++) scanf("%lf",&p[i]);
	A.init();
	B=qpow(A,n);
	printf("%.8lf\n",1-B.v[0][0]);
	return 0;
}