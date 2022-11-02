#include<bits/stdc++.h>
using namespace std;
string tab[1000005];
int war[1000005];
vector<bool> ok[1000005];
vector<bool> odw[1000005];
void dfs1(int a,int b)
{
    odw[a][b]=true;
    if(tab[a+1][b]=='.'&&odw[a+1][b]==false)
        dfs1(a+1,b);
    if(tab[a][b+1]=='.'&&odw[a][b+1]==false)
        dfs1(a,b+1);
    if(ok[a+1][b]==true||ok[a][b+1]==true)
        ok[a][b]=true;
}
void dfs2(int a,int b,int c)
{
    odw[a][b]=true;
    war[c]++;
    if(tab[a+1][b]=='.'&&odw[a+1][b]==false&&ok[a+1][b]==true)
        dfs2(a+1,b,c+1);
    if(tab[a][b+1]=='.'&&odw[a][b+1]==false&&ok[a][b+1]==true)
        dfs2(a,b+1,c+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string xd="",wtf,jd;
    for(int x=0;x<=b+1;x++)
        xd+='#';
    tab[0]=xd;
    tab[a+1]=xd;
    for(int x=1;x<=a;x++)
    {
        cin>>wtf;
        xd="#";
        xd+=wtf;
        xd+="#";
        tab[x]=xd;
    }
    for(int x=0;x<=a+1;x++)
        for(int y=0;y<=b+1;y++)
        {
            ok[x].push_back(false);
            odw[x].push_back(false);
        }
    ok[a][b]=true;
    dfs1(1,1);
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            odw[x][y]=false;
    if(ok[1][1]==false)
    {
        cout<<0;
        return 0;
    }
    dfs2(1,1,0);
    for(int x=1;x<a+b-2;x++)
        if(war[x]==1)
    {
        cout<<1;
        return 0;
    }
    cout<<2;

	return 0;
}