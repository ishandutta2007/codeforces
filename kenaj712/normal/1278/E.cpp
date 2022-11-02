#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
int label[1000005][2];
int licz=1;
void dfs(int a,int b)
{
    for(auto x:pol[a])
        if(x!=b)
            dfs(x,a);
    label[a][0]=licz;
    licz++;
    reverse(pol[a].begin(),pol[a].end());
    for(auto x:pol[a])
        if(x!=b)
        {
            label[x][1]=licz;
            licz++;
        }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    dfs(1,-1);
    label[1][1]=2*a;
    for(int x=1;x<=a;x++)
        cout<<label[x][0]<<" "<<label[x][1]<<'\n';
	return 0;
}