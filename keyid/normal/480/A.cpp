#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=5000;

struct exam
{
    int a,b;
};

bool cmp(exam c,exam d)
{
    if (c.a!=d.a) return c.a<d.a;
    return c.b<d.b;
}

int main()
{
    exam test[MAXN];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&test[i].a,&test[i].b);
    sort(test,test+n,cmp);
    int day=test[0].b;
    for (int i=1;i<n;i++)
    {
        if (day<=test[i].b) day=test[i].b;
        else day=test[i].a;
    }
    printf("%d",day);
    return 0;
}