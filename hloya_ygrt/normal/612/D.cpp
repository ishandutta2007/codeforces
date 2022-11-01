#include <bits\stdc++.h>

using namespace std;
    const int maxn=2e6;
    pair<int,bool> a[maxn];
    vector<pair<int,int> > ans;
#define f first
#define s second
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    for (int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        a[i*2].f=l;a[i*2].s=0;
        a[i*2+1].f=r; a[i*2+1].s=1;
    }

    sort(a,a+2*n);
    int l=0,r=0,in=1;

    while (l<=r&&r<2*n)
    {
        while (in<k)
        {
            r++;

            if (r==2*n)
                break;

            if (a[r].s==0)
                in++;
            else
                in--;
        }
        int x=r;
        if (in>=k)
        {


        while (in>=k&&r<2*n)
        {
            r++;
            if (a[r].s==0)
                in++;
            else
                in--;
        }
        ans.push_back(make_pair(a[x].f,a[r].f));
        }
        l=r;
    }
    printf("%d\n",ans.size());

    for (int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].f,ans[i].s);
    }
    return 0;
}