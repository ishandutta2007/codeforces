#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
 
namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) {
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x;
}
}using namespace IO;
 
int i,j,k,n,m,t,a[200501],b[200501],d[200501];
bool c[200501];
ll res;
int main(){
	t=rd();
	while(t--){
		n=rd();m=rd();res=1;
		memset(c,0,sizeof(bool)*n+3);
		for(i=1;i<=n;i++){
			a[i]=rd();
			d[a[i]]=i;
		}
		a[0]=a[n+1]=0;
		c[0]=c[n+1]=1;
		for(i=1;i<=m;i++){
			b[i]=rd();c[b[i]]=1;
		}
		for(i=1;i<=m;i++){
			k=2;j=d[b[i]];
			if(c[a[j-1]]){k--;}
			if(c[a[j+1]]){k--;}
			if(k==2){res=res*k%M;}
			if(k==0){res=0;break;}
			c[b[i]]=0;
		}
		printf("%lld\n",res);
	}
}