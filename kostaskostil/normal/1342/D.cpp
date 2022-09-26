#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=5e5+100;

int n, k;
int a[nmax];
int c[nmax];

vector<vector<int> > f(int x)
{
    vector<vector<int> > ans(x);
    for (int i=0; i<n; i++)
    {
        ans[i%x].push_back(a[i]);
    }
    for (int i=0; i<x; i++){
        int cnt=0;
        for (int j:ans[i])
        {
            cnt++;
            if (cnt>c[j])
                return {};
        }
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n, [](int x, int y){return x>y;});
    for (int i=1; i<=k; i++)
        cin>>c[i];
    int l=0;
    int r=n;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m).size()>0)
            r=m;
        else
            l=m;
    }
    auto ans=f(r);
    cout<<ans.size()<<"\n";
    for (auto v:ans)
    {
        cout<<v.size()<<" ";
        for (int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }
}