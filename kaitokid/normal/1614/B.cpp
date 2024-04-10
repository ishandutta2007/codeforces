#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[2000009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{

int n;
cin>>n;
vector<pair<int,int> >v;
for(int i=1;i<=n;i++)
{
    int x;
    cin>>x;
    v.push_back({x,i});
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
ll res=0;
for(int i=0;i<v.size();i++)
{
    int u=(i/2)+1;
    res+=v[i].first*1LL*2*u;
    if(i%2)u*=-1;
    ans[v[i].second]=u;

}
cout<<res<<endl;
for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
cout<<endl;

}
	return 0;
}