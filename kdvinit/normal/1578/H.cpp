#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<string,int> aa,pair<string,int> bb)
{
    string a=aa.first;
    string b=bb.first;
    int n=a.size();
    for(int i=0;i<n;i++)
        {
            if(a[i]==b[i]){continue;}
            if(a[i]<b[i])
                {
                    if(i%2){return false;}
                    else{return true;}
                }
            else
                {
                    if(i%2){return true;}
                    return false;
                }
        }
    return (aa.second<bb.second);
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<string,int>> v(n);
    for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].second=i;
        }
    sort(v.begin(),v.end(),compare);
    for(auto x:v){cout<<x.second+1<<" ";}
}