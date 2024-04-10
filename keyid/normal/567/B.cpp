#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXX=1000005;

bool app[MAXX];

int main()
{
    int n;
    scanf("%d",&n);
    char op[5];
    int ans=0,size=0;
    for (int x;n--;)
    {
        scanf("%s%d",op,&x);
        if (op[0]=='+') ans=max(ans,++size);
        else
            if (!app[x]) ans++;
            else size--;
        app[x]=true;
    }
    printf("%d",ans);
    return 0;
}