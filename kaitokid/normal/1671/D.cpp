#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,a[200009];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        cin>>a[1];
        ll sum=0;
        for(int i=2;i<=n;i++){cin>>a[i];sum+=abs(a[i]-a[i-1]);}
        ll tmp=min(a[1],a[n])-1;
        for(int i=1;i+1<=n;i++)
            tmp=min(tmp,(min(a[i],a[i+1])-1)*2);
        sum+=tmp;
        tmp=x-max(a[1],a[n]);
        for(int i=1;i+1<=n;i++)
            tmp=min(tmp,(x-max(a[i],a[i+1]))*2);
        for(int i=1;i<=n;i++)
                if(a[i]>=x)tmp=0;
        sum+=tmp;
        cout<<sum<<endl;

    }
    return 0;

}