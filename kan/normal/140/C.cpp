#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=100005;

pair <int,int> a[maxn];
vector <int> answer[maxn];
bool bad[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i+1;
    }
    sort(a,a+n);
    int l=0;
    int r=n/3+1;
    while (r-l>1)
    {
        int m=(r+l)/2;
        int ans=0;
        int curk=1;
        for (int i=1;i<n;i++)
        {
            if (a[i].first!=a[i-1].first)
            {
                ans=ans+max(0,curk-m);
                curk=0;
            }
            curk++;
        }
        ans=ans+max(0,curk-m);
//        cerr << l << ' ' << m << ' ' << r << ' ' << ans << endl;
        if (m*3>n-ans) r=m;
        else l=m;
    }
    int ans=l;
    memset(bad,0,sizeof(bad));
    int curk=1;
    if (curk>ans) bad[0]=1;
    for (int i=1;i<n;i++)
    {
        if (a[i].first!=a[i-1].first)
        {
            curk=0;
        }
        curk++;
        if (curk>ans) bad[i]=1;
    }
    cout << ans << endl;
    for (int i=0;i<n;i++) answer[i].resize(0);
    curk=1;
    for (int i=0;i<n;i++) if (!bad[i])
    {
        if (curk>ans) curk=1;
        answer[curk].push_back(a[i].first);
        curk++;
    }
    for (int i=1;i<=ans;i++) cout << answer[i][2] << ' ' << answer[i][1] << ' ' << answer[i][0] << "\n";
    return 0;
}