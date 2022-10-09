#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,r;

int main(){
   scanf("%d%d%d",&a,&b,&r);
   if (a>=2*r && b>=2*r) printf("First\n"); else printf("Second\n");
   return 0;
}