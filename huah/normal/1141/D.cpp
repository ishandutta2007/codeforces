#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
vector<int>x[27],y[27];
queue<pair<int,int> >q;
int main()
{
    cin>>n>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='?') x[0].push_back(i+1);
        else x[a[i]-'a'+1].push_back(i+1);
        if(b[i]=='?') y[0].push_back(i+1);
        else y[b[i]-'a'+1].push_back(i+1);
    }
    for(int i=1;i<=26;i++)
    {
        while(x[i].size()&&y[i].size())
        {
            q.push(make_pair(x[i][x[i].size()-1],y[i][y[i].size()-1]));
            x[i].pop_back();
            y[i].pop_back();
        }
        while(x[i].size()&&y[0].size())
        {
            q.push(make_pair(x[i][x[i].size()-1],y[0][y[0].size()-1]));
            x[i].pop_back();
            y[0].pop_back();
        }
        while(y[i].size()&&x[0].size())
        {
            q.push(make_pair(x[0][x[0].size()-1],y[i][y[i].size()-1]));
            x[0].pop_back();
            y[i].pop_back();
        }
    }
    while(x[0].size()&&y[0].size())
    {
        q.push(make_pair(x[0][x[0].size()-1],y[0][y[0].size()-1]));
            x[0].pop_back();
            y[0].pop_back();
    }
    printf("%d\n",q.size());
    while(!q.empty())
    {
        pair<int,int>now=q.front();q.pop();
        printf("%d %d\n",now.first,now.second);
    }
}