#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[1000005];
bool odw[1000005];
vector<int> v;
priority_queue<int> q;
void dfs(int a)
{
    odw[a]=true;
    v.push_back(a);
    for(int x=0;x<polaczenia[a].size();x++)
        q.push(-polaczenia[a][x]);
    bool czy=false;
    while(0==0)
    {
        if(q.empty()==true)
            break;
        if(odw[-q.top()]==true)
            q.pop();
        else
        {
             czy=true;
             break;
        }


    }
    if(czy==true)
    {
        int pom=-q.top();
        q.pop();
        dfs(pom);
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	cin>>a>>b;
	while(b--)
    {
        cin>>c>>d;
        polaczenia[c].push_back(d);
        polaczenia[d].push_back(c);
    }
    dfs(1);
    for(int x=0;x<a;x++)
        cout<<v[x]<<" ";
	return 0;
}