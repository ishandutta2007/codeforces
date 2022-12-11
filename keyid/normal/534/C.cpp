#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int d[MAXN];

int main()
{
    int n;
    LL a,s=0;
    scanf("%d%I64d",&n,&a);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
        s+=d[i];
    }
    for (int i=0;i<n;i++) printf("%d ",(int)(max(0LL,a-(s-d[i])-1)+max(0LL,d[i]-(a-(n-1)))));
    return 0;
}