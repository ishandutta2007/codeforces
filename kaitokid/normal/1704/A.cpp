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
        int n,m;
        string a,b;
        cin>>n>>m>>a>>b;
        bool ans=false;
        for(int i=0;i<=n-m;i++)
            if(a[i]==b[0])ans=true;
        for(int i=1;i<m;i++)
        if(b[i]!=a[n-m+i])ans=false;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;

}