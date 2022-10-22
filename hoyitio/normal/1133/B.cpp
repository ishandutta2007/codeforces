#include<iostream>.

#include<cstdio>

using namespace std;
int a[200010];
int cnt[110];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        cnt[t%m]++;
    }
    int ans = 0;
    ans+=cnt[0]/2;
    ans*=2;
    for(int i = 1 ; i <= m/2 ; i++)
    {
        if(i==m-i){ans+=(cnt[i]/2)*2;}
        else
            ans+=min(cnt[i],cnt[m-i])*2;
    }
    cout<<ans<<endl;
    return 0;
}