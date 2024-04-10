#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n,a,b;
        cin>>n>>a>>b>>s;
        int ans=a*n;
        if(b>0){ans+=b*n;cout<<ans<<endl;continue;}
        int u=1;
        for(int i=1;i<n;i++)if(s[i]!=s[i-1])u++;
        u=1+u/2;
        ans+=u*b;
        cout<<ans<<endl;
}
return 0;
}