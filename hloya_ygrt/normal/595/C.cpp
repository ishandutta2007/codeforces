#include <stdio.h>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;
int comp(int a,int b)
{
    return min(a,b);
}
int main()
{
    vector <int> b;
    //list <int> a;
   // list <int>::iterator i1;
    int n,ans,r,l;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&ans);
        b.push_back(ans);
    }
    sort(b.begin(),b.end());
    ans=2e9;
    for (int i=0;i<n/2;i++)
    {
        ans=min(b[i+n/2]-b[i],ans);
    }
    printf("%d",ans);
    return 0;
}