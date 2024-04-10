#include <bits\stdc++.h>

using namespace std;
    vector<pair<int,int> > a;

int main()
{
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end());

    long long ans=0;
    for (int i=1;i<n;i++)
    {
        ans+=abs(a[i].second-a[i-1].second);
    }
    cout<<ans;
    return 0;
}