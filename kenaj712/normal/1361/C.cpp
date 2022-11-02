#include<bits/stdc++.h>
using namespace std;
pair<int,int> tab[1100005];
vector<pair<int,int>> pol[1100005];
bool odw[1100005];
vector<pair<pair<int,int>,int>> out;
vector<pair<pair<int,int>,int>> w;
void dfs(int a)
{
    while(!pol[a].empty())
    {
        if(odw[pol[a].back().second])
            pol[a].pop_back();
        else
        {
            w.push_back(make_pair(make_pair(pol[a].back().first,a),pol[a].back().second));
            odw[pol[a].back().second]=true;
            dfs(pol[a].back().first);
        }
    }
    if(w.empty()==false)
    {
        out.push_back(w.back());
        w.pop_back();
    }

}
bool check(int a)
{
    for(int x=0;x<=(1<<20);x++)
        if(pol[x].size()%2)
            return false;
    for(int x=0;x<=(1<<20);x++)
        if(pol[x].size())
        {
            dfs(x);
            break;
        }
    //reverse(out.begin(),out.end());
    if(out.size()!=a)
    {
        out.resize(0);
        return false;
    }
    return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        int c,d;
        cin>>c>>d;
        tab[x]=make_pair(c,d);
    }
    if(a==1)
    {
        int pom=tab[1].first^tab[1].second;
        int licz=0;
        if(pom==0)
            licz=20;
        else
        {
            while(pom%2==0)
            {
                pom/=2;
                licz++;
            }
        }
        cout<<licz<<'\n'<<1<<" "<<2;
        return 0;
    }
    for(int x=20;x>=0;x--)
    {
        int pom=(1<<x)-1;
        for(int y=1;y<=a;y++)
        {
            pol[tab[y].first&pom].push_back(make_pair(tab[y].second&pom,y));
            pol[tab[y].second&pom].push_back(make_pair(tab[y].first&pom,y));
        }
        if(check(a))
        {
            cout<<x<<'\n';
            for(auto x:out)
            {
                if(x.first.first==(tab[x.second].first&pom) && x.first.second==(tab[x.second].second&pom))
                    cout<<x.second*2-1<<" "<<x.second*2<<" ";
                else
                    cout<<x.second*2<<" "<<x.second*2-1<<" ";
            }
            return 0;
        }
        for(int x=0;x<=(1<<20);x++)
        {
            pol[x].resize(0);
            odw[x]=false;
        }
    }
	return 0;
}