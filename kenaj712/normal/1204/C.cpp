#include<bits/stdc++.h>
using namespace std;
vector<int> pol[105];
bool odw[105];
int mini[105][105];
queue<pair<int,int>> q;
vector<int> v;
void bfs(int a)
{
    int pom1,pom2;
    q.push(make_pair(a,0));
    odw[a]=true;
    while(q.empty()==false)
    {
        pom1=q.front().first,pom2=q.front().second;
        mini[a][pom1]=pom2;
        q.pop();
        for(auto x:pol[pom1])
            if(odw[x]==false)
            {
                odw[x]=true;
                q.push(make_pair(x,pom2+1));
            }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    char b;
    cin>>a;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
            mini[x][y]=1e8;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
        {
            cin>>b;
            if(b=='1')
                pol[x].push_back(y);
        }
    for(int x=1;x<=a;x++)
    {
        bfs(x);
        for(int x=1;x<=a;x++)
            odw[x]=false;
    }
    int c,d,e,last,pom1=0,pom2;
    cin>>d;
    cin>>c;
    last=c;
    pom1=1;
    v.push_back(c);
    for(int x=2;x<=d;x++)
    {
        cin>>e;
        if(mini[c][e]<pom1)
        {
            v.push_back(last);
            c=last;
            pom1=1;
        }
        pom1++;
        last=e;
    }
    v.push_back(last);
    cout<<v.size()<<'\n';
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}