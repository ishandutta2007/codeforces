#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int ans=l1+l2;
        if(l2>=l1&&l2<=r1)ans=min(ans,l2);
        if(l1>=l2 && l1<=r2)ans=min(ans,l1);
        cout<<ans<<endl;

           }

    return 0;
}