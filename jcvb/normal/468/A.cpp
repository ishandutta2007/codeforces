#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n;

int main()
{
    scanf("%d",&n);
    if(n<=3){
        printf("NO\n");
        return 0;
    }
    if(n&1){
        printf("YES\n2 * 1 = 2\n3 - 2 = 1\n5 + 1 = 6\n4 * 6 = 24\n");
    }else{
        printf("YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
    }
    for (int i=n;i-1>=5;i-=2){
        printf("%d - %d = 1\n",i,i-1);
        printf("24 * 1 = 24\n");
    }
    return 0;
}