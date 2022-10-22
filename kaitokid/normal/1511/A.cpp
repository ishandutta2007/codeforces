#include <bits/stdc++.h>

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
        int n,ans=0,x;
        cin>>n;
        for(int i=0;i<n;i++){cin>>x;if(x!=2)ans++;}
        cout<<ans<<endl;
    }
    return 0;
}