//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,N=1e5;
const ull iv5=14757395258967641293ull;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct poly{
	ull x[10];
	void clear(){for(int i=0;i<10;i++)x[i]=0;return ;}
	poly operator +(poly p)const{
		poly res;
		for(int i=0;i<10;i++)res.x[i]=x[i]+p.x[i];
		return res;
	}
	poly operator *(poly p)const{
		poly res;
		for(int i=0;i<10;i++)res.x[i]=0;
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)res.x[(i+j)%10]+=x[i]*p.x[j];
		return res;
	}
	poly operator *(ull v)const{
		poly res;
		for(int i=0;i<10;i++)res.x[i]=x[i]*v;
		return res;
	}
	poly move(int b){
		poly res;
		for(int i=0;i<10;i++)res.x[(i+b)%10]=x[i];
		return res;
	}
}f[maxn];
poly power(poly x,int b){
	poly res;
	res.clear();res.x[0]=1;
	while(b){
		if(b&1)res=res*x;
		x=x*x;
		b>>=1;
	}
	return res;
}
const int pw[]={1,10,100,1000,10000,100000};
const ull val=iv5*iv5*iv5*iv5*iv5;
void FWT_10(poly *f,bool op){
	for(int c=0;c<5;c++){
		for(int i=0;i<N;i+=pw[c+1]){
			for(int j=0;j<pw[c];j++){
				poly A[10],B[10];
				for(int k=0;k<10;k++)A[k]=f[i+j+k*pw[c]],B[k].clear();
				for(int k=0;k<10;k++)
					for(int l=0;l<10;l++)
						B[k]=B[k]+A[l].move(op?(10-(k*l%10)):(k*l%10));
				for(int k=0;k<10;k++)f[i+j+k*pw[c]]=B[k];
			}
		}
	}
	return ;
}
const ull P[]={1,-1ull,1,-1ull,1};
ull calc(poly p){
	for(int i=9;i>=4;i--){
		ull v=p.x[i];
		for(int j=1;j<=4;j++)p.x[i-j]-=v*P[4-j];
	}
	ull res=p.x[0];
	res*=val;res>>=5;
	return res%(1ull<<58);
}
int main(){
    int n;
	n=read();
	for(int i=0;i<N;i++)f[i].clear();
	for(int i=1;i<=n;i++)f[read()].x[0]++;
	FWT_10(f,0);
	for(int i=0;i<N;i++)f[i]=power(f[i],n);
    FWT_10(f,1);
	for(int i=0;i<n;i++)printf("%llu\n",calc(f[i]));
	return 0;
}