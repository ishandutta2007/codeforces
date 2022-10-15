/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=n+1;

    int ans=0,lst2=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(i<=n && a[i]==a[j]) i++;
        int diff=i-j;
        i--;

        if(diff==1)
        {
            ans+=1;
            if(lst2==j-2 && a[lst2]==a[j]) lst2=i;
        }
        else
        {
            ans+=2;
            if(lst2==j-2 && a[lst2]==a[j]) ans--;
            lst2=i;
        }
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}