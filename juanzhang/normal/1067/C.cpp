#include<cstdio>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int v1=i/3*2,v2=i%3;
        if(v2==1)v1++;
        printf("%d %d\n",v1,v2);
    }
}