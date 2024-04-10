#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int cot;
        scanf("%d",&cot);
        while(cot--)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
    }
    int ma=0;
    for(int i=1;i<=100;i++) ma=max(ma,a[i]);
    for(int i=1;i<=100;i++)
        if(a[i]==ma) printf("%d ",i);
}