#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=501000;
ll a[maxn],sum,sz,p1,p2;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main()
{
	for(register int q=read();q;--q){
		if(read()&1){
			a[++p1]=read();
			while(p2<p1-1&&1.0*(a[p1]+sum)/(p2+1)>1.0*(a[p1]+sum+a[p2+1])/(p2+2))++p2,sum+=a[p2];
		}
		else printf("%.10lf\n",a[p1]-1.0*(a[p1]+sum)/(p2+1));
	}
	return 0;
}