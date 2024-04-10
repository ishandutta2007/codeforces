#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m,a,b;
int d[60];
string ans[58];
int main()
{
    ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    cin>>n>>m>>a>>b;
    if(m*b!=a*n){cout<<"NO\n";continue;}

string g;
    for(int i=0;i<m;i++){d[i]=0;g+='0';}
    bool e=true;
    for(int i=0;i<n;i++)
    {
        ans[i]=g;
        vector<pair<int,int> >r;
        for(int j=0;j<m;j++)
       if(d[j]<b) r.push_back({d[j],j});
    if(r.size()<a){e=false;break;}
    sort(r.begin(),r.end());
    for(int j=0;j<a;j++){ans[i][r[j].second]='1';d[r[j].second]++;}

    }
    if(!e){cout<<"NO\n";continue;}
    cout<<"YES\n";
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
}

    return 0;
}