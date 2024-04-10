#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n;
int pr[1009];
bool no[1009];
vector<int> a[1009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=2;i<=n;i++)
{cin>>pr[i];
no[pr[i]]=true;
a[pr[i]].push_back(i);
}
for(int i=1;i<=n;i++)
{
if(!no[i])continue;
int d=0;
for(int j=0;j<a[i].size();j++)
if(!no[a[i][j]])d++;

if(d<3){cout<<"No";return 0;}

}
cout<<"Yes";
return 0;}