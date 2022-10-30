#include<bits/stdc++.h>
using namespace std;
long long licz1,licz2,licz3;
long long f,b,c;
int w;
bool czy=false;
bool odw[400005];
vector <int> polaczenia[400005];
void dfs2(int a)
{
    odw[a]=true;
    licz2++;
    //cout<<"XD";
    for(int x=0;x<polaczenia[a].size();x++)
        if(odw[polaczenia[a][x]]==false)
                dfs2(polaczenia[a][x]);
}
void dfs1(int a)
{
    odw[a]=true;
    //cout<<a<<'\n';
    for(int x=0;x<polaczenia[a].size();x++)
    {
        if(odw[polaczenia[a][x]]==false)
        {
            if(polaczenia[a][x]==c)
                dfs2(polaczenia[a][x]);
            else
                dfs1(polaczenia[a][x]);
        }
        if(odw[c]==true&&czy==false&&a==b)
        {
            w=polaczenia[a][x];
            czy=true;
        }

    }
}
void dfs3(int a)
{
    odw[a]=true;
    licz3++;
    for(int x=0;x<polaczenia[a].size();x++)
        if(odw[polaczenia[a][x]]==false)
                dfs3(polaczenia[a][x]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>f>>b>>c;
    int d,e;
    for(int x=0;x<f-1;x++)
    {
        cin>>e>>d;
        polaczenia[e].push_back(d);
        polaczenia[d].push_back(e);
    }
    dfs1(b);
    for(int x=1;x<=f;x++)
        odw[x]=false;
    odw[b]=true;
    odw[c]=true;
    if(w!=c)
        dfs3(w);
    //cout<<licz2<<" "<<licz3;

    cout<<f*(f-1)-licz2*(f-licz2-licz3);
	return 0;
}