#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;
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
}
using namespace IO;
int n,m,b[1050],res=1,i,j,a;

int main(){
	n=rd();m=rd();
	if(n>=m+1){puts("0");return 0;}
	for(i=1;i<=n;i++){
		b[i]=rd();
	}
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			a=abs(b[j]-b[i])%m;
			res=a*res%m;
			if(res==0){puts("0");return 0;}
		}
	}
	printf("%d\n",res);
}