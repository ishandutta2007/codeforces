// Hydro submission #614c8785e7c893b91cbb5006@1632405503323
#include <bits/stdc++.h>
using namespace std;
const int N=110;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int r,s,p;
double f[N][N][N];
double ar,as,ap;
int main(){
	r=read();s=read();p=read();
	f[r][s][p]=1.0;
	for(int i=r;i>=0;i--){
		for(int j=s;j>=0;j--){
			for(int k=p;k>=0;k--){
				if(j||k) f[i][j][k]+=f[i+1][j][k]*((i+1)*k)/((i+1)*(j+k)+j*k);
				if(i||k) f[i][j][k]+=f[i][j+1][k]*((j+1)*i)/((j+1)*(i+k)+i*k);
				if(i||j) f[i][j][k]+=f[i][j][k+1]*((k+1)*j)/((k+1)*(i+j)+i*j);
			}
		}
	}
	for(int i=1;i<=r;i++)
		ar+=f[i][0][0];
	for(int i=1;i<=s;i++)
		as+=f[0][i][0];
	for(int i=1;i<=p;i++)
		ap+=f[0][0][i];
	printf("%.9lf %.9lf %.9lf",ar,as,ap);
	return 0;
}