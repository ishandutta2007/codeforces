#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=101000;
const double g=9.8;
int n,v,m;
int ba[maxn],bw[maxn];
double a[maxn],xw[maxn],yw[maxn];
double ansx[maxn],ansy[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
bool cmp2(int x,int y){
	return xw[x]<xw[y];
}
int main()
{
	n=read();v=read();
	for(register int i=0;i<n;++i){
		ba[i]=i;scanf("%lf",&a[i]);
		ansx[i]=v*v*sin(2*a[i])/g;
	}
	m=read();
	for(register int i=0;i<m;++i)
		bw[i]=i,scanf("%lf%lf",&xw[i],&yw[i]);
	sort(ba,ba+n,cmp);
	sort(bw,bw+m,cmp2);
	for(register int i=0,j=0;i<n&&j<m;++j){
		while(i<n&&ansx[ba[i]]<=xw[bw[j]])++i;
		while(i<n){
		    double yr=xw[bw[j]]*tan(a[ba[i]])-g*xw[bw[j]]*xw[bw[j]]/(2*v*v*cos(a[ba[i]])*cos(a[ba[i]]));
		    if(yr>yw[bw[j]])break;
		    ansx[ba[i]]=xw[bw[j]];
		    ansy[ba[i]]=yr;
		    ++i;
		}
	}for(register int i=0;i<n;++i)
		printf("%.10lf %.10lf\n",ansx[i],ansy[i]);
	return 0;
}