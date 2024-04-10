#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        string s;
        cin>>s;
        vector<int>r,b;
        for(int i=0;i<n;i++)
            if(s[i]=='B')b.push_back(a[i]);
        else r.push_back(a[i]);
        sort(b.begin(),b.end());
        sort(r.begin(),r.end());
        bool ans=true;
        for(int i=0;i<b.size();i++)if(b[i]<=i)ans=false;
        reverse(r.begin(),r.end());
        for(int i=0;i<r.size();i++)if(r[i]>n-i)ans=false;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}