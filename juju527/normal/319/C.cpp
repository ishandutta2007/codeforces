#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define R (q.size()-1)
const int maxn=1e5+5;
ll a[maxn],b[maxn];
ll f[maxn];
deque<int>q;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF319C.in","r",stdin);
//    freopen("CF319C.out","w",stdout);
   	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
    f[1]=0;
	q.push_back(1);
	for(int i=2;i<=n;i++){
		while(q.size()>=2&&(1.0*(f[q[1]]-f[q[0]])/(b[q[0]]-b[q[1]]))<a[i])q.pop_front();
		int j=q[0];
		f[i]=f[j]+1ll*b[j]*a[i];
		while(q.size()>=2&&(1.0*(f[i]-f[q[R]])/(b[q[R]]-b[i]))<(1.0*(f[q[R]]-f[q[R-1]])/(b[q[R-1]]-b[q[R]])))q.pop_back();
		q.push_back(i);
	}
	printf("%lld\n",f[n]);
	return 0;
}