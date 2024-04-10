#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
using namespace std;
const int N=3e5+5;
int n,a[N],x,y,j,ts,t[N*31][2],v[N*31],an;
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);ts=1;
	fo(i,1,n)R(a[i]);
	fo(i,1,n){
		R(x);j=1;
		fd(k,0,29){
			y=(x&(1<<k))>0;
			if(!t[j][y])t[j][y]=++ts;
			j=t[j][y];v[j]++;
		}
	}
	fo(i,1,n){
		an=x=a[i];j=1;
		fd(k,0,29){
			y=(x&(1<<k))>0;
			if(v[t[j][y]])(y?(an^=1<<k):0),j=t[j][y],v[j]--;
			else (!y?(an^=1<<k):0),j=t[j][!y],v[j]--;
		}
		printf("%d ",an);
	}
}