#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int n;
scanf("%d",&n);
while(n--){
int t;
scanf("%d",&t);
if(360%(180-t)==0)printf("YES\n");
else printf("NO\n");
}
return 0;
}