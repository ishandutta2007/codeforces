#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,d1,d2,d3,ans1,ans2,ans3,ans4;
    scanf("%d %d %d",&d1,&d2,&d3);

    ans1=d1+d2+d3;
    ans2=2*d1+2*d2;
    ans3=2*d1+2*d3;
    ans4=2*d2+2*d3;
    ans1=min(ans1,ans2);
    ans1=min(ans1,ans3);
    ans1=min(ans1,ans4);
    printf("%d",ans1);
    return 0;
}