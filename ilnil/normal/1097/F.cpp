#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,q,x,y,z,v,op,mu[7005],p[7005],ps;
bool bz[7005];
bitset<7005>a[N],b[7005],an[7005];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int main(){
	R(n);R(q);
	mu[1]=1;
	fo(i,2,7000){
		if(!bz[i])p[++ps]=i,mu[i]=1;
		for(int j=1,u;(u=i*p[j])<=7000;j++){
			bz[u]=1;
			if(i%p[j]==0)break;
			mu[u]=mu[i];
		}
	}
	fo(i,1,7000){
		fo(j,1,i)if(i%j==0)b[i][j]=1;
		fo(j,1,7000/i)an[i][i*j]=mu[j];
	}
	for(;q--;){
		R(op);R(x);R(y);
		if(op==1){
			a[x]=b[y];
		}
		if(op==2){
			R(z);
			a[x]=a[y]^a[z];
		}
		if(op==3){
			R(z);
			a[x]=a[y]&a[z];
		}
		if(op==4){
			if((a[x]&an[y]).count()&1)putchar('1');else putchar('0');
		}
	}
}