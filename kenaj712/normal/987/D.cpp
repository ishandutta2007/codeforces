#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[100005];
bool odw[100005];
vector<int> rodzaj[105];
queue< pair<int,int> > q;
vector<int> koszty[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f;
    for(int x=1;x<=a;x++)
    {
        cin>>e;
        rodzaj[e].push_back(x);
    }
    for(int x=0;x<b;x++)
    {
        cin>>e>>f;
        polaczenia[e].push_back(f);
        polaczenia[f].push_back(e);
    }
    for(int x=1;x<=c;x++)
    {
        for(int y=0;y<rodzaj[x].size();y++)
        {
            odw[rodzaj[x][y]]=true;
            koszty[rodzaj[x][y]].push_back(0);
            q.push(make_pair(rodzaj[x][y],0));
        }
        while(q.empty()==false)
        {
            int pom1=q.front().first,pom2=q.front().second;
            q.pop();
            for(int y=0;y<polaczenia[pom1].size();y++)
            {
                if(odw[polaczenia[pom1][y]]==false)
                {
                    odw[polaczenia[pom1][y]]=true;
                    koszty[polaczenia[pom1][y]].push_back(pom2+1);
                    q.push(make_pair(polaczenia[pom1][y],pom2+1));
                }
            }
        }
        for(int x=1;x<=a;x++)
            odw[x]=false;
    }
    for(int x=1;x<=a;x++)
    {
        sort(koszty[x].begin(),koszty[x].end());
        int pom3=0;
        for(int y=0;y<d;y++)
            pom3+=koszty[x][y];
        cout<<pom3<<" ";
    }

	return 0;
}