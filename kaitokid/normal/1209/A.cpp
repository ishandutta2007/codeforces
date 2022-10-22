#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,a[200],ans;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)continue;
        ans++;
        for(int j=i+1;j<n;j++)if(a[j]%a[i]==0)a[j]=0;
    }
    cout<<ans;
    return 0;
}