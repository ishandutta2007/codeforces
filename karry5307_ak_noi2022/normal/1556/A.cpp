#include<cstdio>
using namespace std;
int a,b,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a%2!=b%2)
        {
            printf("-1\n");
            continue;
        }
        if(a==0 && b==0) printf("0\n");
        else if(a==b) printf("1\n");
        else printf("2\n");
    }
}