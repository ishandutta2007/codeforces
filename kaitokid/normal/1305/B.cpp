#include <bits/stdc++.h>

using namespace std;
int n;
string s;
vector<pair<int,int> >ans;
int main()
{
    ios::sync_with_stdio(0);
cin>>s;
 n=s.size();
int i=0,j=n-1;
while(i<n&&j>=0&&j>i)
{
    while(s[i]!='('&&i<n)i++;
    while(s[j]!=')'&&j>=0)j--;
    if(i==n||j==0||i>j)break;
    ans.push_back({i,j});
    i++;
    j--;
}
n=ans.size();
if(n==0){cout<<0;return 0;}
cout<<1<<endl<<2*n<<endl;
for(int i=0;i<n;i++)cout<<ans[i].first+1<<" ";
for(int i=n-1;i>=0;i--)cout<<ans[i].second+1<<" ";
    return 0;
}