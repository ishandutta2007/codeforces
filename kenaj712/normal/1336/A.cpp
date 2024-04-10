#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
int subtree[1000005];
bool odw[1000005];
vector<int> v;
void dfs(int a,int b)
{
    odw[a]=true;
    for(auto x:pol[a])
    {
        if(!odw[x])
        {
            dfs(x,b+1);
            subtree[a]+=subtree[x];
        }
    }
    subtree[a]++;
    v.push_back(subtree[a]-b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    b=a-b;
    int c,d;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    dfs(1,1);
    sort(v.begin(),v.end());
    long long sum=0;
    reverse(v.begin(),v.end());
    for(int x=0;x<b;x++)
        sum+=v[x];
    cout<<sum;
	return 0;
}