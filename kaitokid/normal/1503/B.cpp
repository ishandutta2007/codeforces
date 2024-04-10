#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> >v[2];
int main()
{int n;
cin>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
v[(i+j)%2].push_back({i,j});
for(int i=0;i<n*n;i++)
{
    int u;
    cin>>u;
    if(u!=1&&!v[0].empty()){cout<<1<<" "<<v[0].back().first<<" "<<v[0].back().second<<endl;fflush(stdout);v[0].pop_back();continue;}
    if(u!=2&&!v[1].empty()){cout<<2<<" "<<v[1].back().first<<" "<<v[1].back().second<<endl;fflush(stdout);v[1].pop_back();continue;}
if(!v[0].empty()){cout<<3<<" "<<v[0].back().first<<" "<<v[0].back().second<<endl;fflush(stdout);v[0].pop_back();continue;}
if(!v[1].empty()){cout<<3<<" "<<v[1].back().first<<" "<<v[1].back().second<<endl;fflush(stdout);v[1].pop_back();continue;}


}
    return 0;
}