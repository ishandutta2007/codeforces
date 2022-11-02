#include<bits/stdc++.h>
using namespace std;
int tab[105][105];
vector<pair<int,pair<int,int>>> v;
bool ok[105][105];
int runner[105][105];
bool taken[105][105];
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=b;y++)
        {
            cin>>tab[x][y];
            v.push_back(make_pair(tab[x][y] , make_pair(x,y)));
        }
    }
    sort(v.begin(),v.end());
    for(int x=0;x<b;x++)
        ok[v[x].second.first][v[x].second.second] = true;
    for(int x=1;x<=b;x++)
    {
        bool siema = false;
        for(int y=1;y<=a;y++)
        {
            bool left = false;
            for(int z=1;z<=b;z++)
                if(ok[y][z] && !taken[y][z])
                    left = true;
            if(!left)
            {
                for(int z=1;z<=b;z++)
                    if(!taken[y][z])
                    {
                        runner[x][y] = tab[y][z];
                        taken[y][z] = true;
                        break;
                    }
            }
            else
            {
                if(!siema)
                {
                    for(int z=1;z<=b;z++)
                        if(!taken[y][z] && ok[y][z])
                        {
                            runner[x][y] = tab[y][z];
                            taken[y][z] = true;
                            break;
                        }
                    siema = true;
                }
                else
                {
                    for(int z=1;z<=b;z++)
                        if(!taken[y][z] && !ok[y][z])
                        {
                            runner[x][y] = tab[y][z];
                            taken[y][z] = true;
                            break;
                        }
                }
            }
        }
    }
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=b;y++)
            cout<<runner[y][x]<<" ";
        cout<<'\n';
    }
    v.resize(0);
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
    {
        ok[x][y] = 0;
        taken[x][y] = 0;
        runner[x][y] = 0;
        tab[x][y] = 0;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}