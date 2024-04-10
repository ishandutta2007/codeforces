#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1009];
int p[1009],s[1009];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){cin>>a[i];p[i]=i;s[i]=i;}
        for(int i=2;i<=n;i++)if(a[p[i-1]]<a[i])p[i]=p[i-1];
        for(int i=n-1;i>=1;i--)if(a[s[i+1]]<a[i])s[i]=s[i+1];
        bool bl=false;
        for(int i=2;i<n;i++)if(p[i]!=i&&s[i]!=i){cout<<"YES\n"<<p[i]<<" "<<i<<" "<<s[i]<<endl;bl=true;break;}
        if(!bl)cout<<"NO\n";

    }
    return 0;
}