#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db long double
#define put putchar
using namespace std;
const int N=2e5+5,mo=1e9+7;
int t,n,x,y,ct[3];
int a[N];
ll ans;
template<class I>
void R(I &n){
	char c;int fh=1;
	for(n=0;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
template<class I>
void P(I n){
	if(n<0)put('-'),n=-n;
	if(!n)put('0');
	int j=0;char o[30];
	for(;n;n/=10)o[++j]=n%10+48;
	for(;j;)put(o[j--]);
}
int main(){
	R(n);
	fo(i,1,n)R(a[i]),ct[a[i]]++;
	int nn=0;
	if(ct[1]>=3){
		a[++nn]=1;a[++nn]=1;a[++nn]=1;
		ct[1]-=3;
	}else{
		if(ct[1]>=1&&ct[2]>=1)a[++nn]=2,a[++nn]=1,ct[1]--,ct[2]--;
		else{
			if(ct[1]>=1)a[++nn]=1,ct[1]--;
		}
	}
	fo(i,1,ct[2])a[++nn]=2;
	fo(i,1,ct[1])a[++nn]=1;
	fo(i,1,nn)printf("%d ",a[i]);
}