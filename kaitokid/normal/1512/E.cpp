#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n,l,r,s;
    cin>>n>>l>>r>>s;
    int z=r-l+1;
    vector<int>q,res;
    int mn=z*(z+1)/2;
    int mx=n*(n+1)/2-(n-z)*(n-z+1)/2;
    if(s<mn||s>mx){cout<<-1<<endl;continue;}
    for(int i=1;i<=z;i++)res.push_back(i);
    res.push_back(n+1);
    for(int i=z-1;i>=0;i--)
    {
        while(mn<s&&res[i]<res[i+1]-1){res[i]++;mn++;}
    }
    for(int i=1;i<res[0];i++)q.push_back(i);
    for(int i=0;i<z;i++)
        for(int u=res[i]+1;u<res[i+1];u++)q.push_back(u);
    for(int i=1;i<l;i++){cout<<q.back()<<" ";q.pop_back();}
    for(int i=0;i<z;i++)cout<<res[i]<<" ";
    for(int i=r+1;i<=n;i++){cout<<q.back()<<" ";q.pop_back();}
    cout<<endl;

    }
    return 0;
}