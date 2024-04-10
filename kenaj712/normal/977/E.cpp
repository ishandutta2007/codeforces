#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[1000005];
int pom=0;
bool odw[1000005];
void dfs(int a,int b)
{
    odw[a]=true;
    if(polaczenia[a].size()!=2)
        pom+=10;
    for(int x=0;x<polaczenia[a].size();x++)
    {
        if(polaczenia[a][x]!=b)
        {
            if(odw[polaczenia[a][x]]==true)
                pom++;
            else
                dfs(polaczenia[a][x],a);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int c,d;
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        polaczenia[c].push_back(d);
        polaczenia[d].push_back(c);
    }
    int suma=0;
    for(int x=1;x<=a;x++)
    {
        pom=0;
        if(odw[x]==false)
            dfs(x,0);
        if(pom==2)
        suma++;
    }
    cout<<suma;
	return 0;
}