#include <bits\stdc++.h>

using namespace std;
    const int maxn=1e5;
    vector <int> a(maxn),best(maxn);
int main()
{
    int n;
    scanf("%d",&n);

    int sum=0;

    for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
    sort(a.rbegin(),a.rend());

    int ozh=sum/n,lish=sum-ozh*n;
    int otkl=0;

    for (int i=0;i<n;i++)
    {
        best[i]=ozh;

        if (lish)
        {
            lish--;
            best[i]++;
        }
        otkl+=abs(a[i]-best[i]);
    }

    printf("%d",otkl/2);
    return 0;
}