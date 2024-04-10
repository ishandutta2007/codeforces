#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int l,r;
    l = r = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        int t;
        scanf("%d",&t);
        if(t==0){l=i;}
        else{r=i;}
    }
    printf("%d",min(l,r));
    return 0;
}