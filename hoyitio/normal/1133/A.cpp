#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int h1,h2,m1,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    int ans = (h2*60+m2-h1*60-m1)/2;
    ans+=h1*60+m1;
    printf("%02d:%02d",ans/60,ans%60);
    return 0;
}