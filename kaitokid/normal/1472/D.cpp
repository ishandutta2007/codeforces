#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
reverse(a,a+n);
ll ans[2];
ans[0]=ans[1]=0;
for(int i=0;i<n;i++)
{
    if(i%2==a[i]%2)ans[i%2]+=a[i];
}
if(ans[0]>ans[1])cout<<"Alice\n";
else if(ans[0]<ans[1])cout<<"Bob\n";
else cout<<"Tie\n";
     }
    return 0;
}