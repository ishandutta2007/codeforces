#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++) cin>>s[i];
        sort(s,s+n);
        int ans=1000;
        for(int i=1;i<n;i++) ans=min(s[i]-s[i-1],ans);
        cout<<ans<<endl;
    }
    return 0;
}