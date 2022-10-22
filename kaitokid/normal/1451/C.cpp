#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int d[30],r[30];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t,n,k;
cin>>t;
while(t--)
{
    for(int i=0;i<29;i++)d[i]=r[i]=0;
    cin>>n>>k;
    string x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++)
    {
        d[x[i]-'a']++;
        r[y[i]-'a']++;
    }
    bool ans=false;
    for(int i=0;i<28;i++)
    {
     if(r[i]>d[i]){ans=true;break;}
     int u=d[i]-r[i];
     if(u%k){ans=true;break;}
     d[i+1]+=u;

    }
    if(ans)cout<<"NO\n";
    else cout<<"YES\n";

}
    return 0;
}