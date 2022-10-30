#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int i,j,k,t,a[20],sb;
ll jc[20]={1},cur=0,l,r,res,n;

void get(ll cur,int n){
	int i,j,k,tmp;
	bool used[20]={0};
	for(i=1;i<=n;i++){
		tmp=1;
		while(cur>=jc[n-i]){cur-=jc[n-i];tmp++;}
		for(j=1,k=0;j<=n;j++){
			if(!used[j]){k++;}
			if(k==tmp){used[j]=1;a[i]=j;break;}
		}
	}
}

int main(){
	for(i=1;i<=16;i++){jc[i]=jc[i-1]*i;}
	n=rd();t=rd();
	get(0,min(16,(int)n));
	while(t--){
		k=rd();
		if(k==2){
			k=rd();cur+=k;sb=1;
		}
		else{
			l=rd();r=rd();
			if(n<=16){
				if(sb){get(cur,n);sb=0;}
				for(i=l,res=0;i<=r;i++){res+=a[i];}
				printf("%lld\n",res);continue;
			}
			if(r<=n-16){printf("%lld\n",(r*r+r-l*l+l)/2);}
			else{
				if(sb){get(cur,16);sb=0;}
				if(l<=n-16){for(i=1,res=0;i<=r-(n-15)+1;i++){res+=n-16+a[i];}printf("%lld\n",((n-16)*(n-16)+(n-16)-l*l+l)/2+res);}
				else{for(i=l-(n-15)+1,res=0;i<=r-(n-15)+1;i++){res+=n-16+a[i];}printf("%lld\n",res);}
			}
		}
	}
}