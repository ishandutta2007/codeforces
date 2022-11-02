#include<bits/stdc++.h>
using namespace std;
char tab[1005][1005];
bool odw[1005][1005];
void dfs(int a,int b,int c,int d)
{
    odw[a][b]=true;
    if(a!=0 && tab[a-1][b]=='#' && odw[a-1][b]==false)
        dfs(a-1,b,c,d);
     if(a!=c && tab[a+1][b]=='#' && odw[a+1][b]==false)
        dfs(a+1,b,c,d);
     if(b!=0 && tab[a][b-1]=='#' && odw[a][b-1]==false)
        dfs(a,b-1,c,d);
        if(b!=d && tab[a][b+1]=='#' && odw[a][b+1]==false)
        dfs(a,b+1,c,d);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            cin>>tab[x][y];
    bool row=false,col=false;
    for(int x=0;x<a;x++)
    {
        int licz=0;
        bool czy1=false,czy2=false;
        for(int y=0;y<b-1;y++)
        {
            if(tab[x][y]=='.' && czy1==false)
                continue;
            if(tab[x][y]=='#' && tab[x][y+1]=='.')
                czy1=true;
            if(tab[x][y]=='.'&&tab[x][y+1]=='#')
                czy2=true;
            if(tab[x][y]=='#')
                licz++;
        }
        if(tab[x][b-1]=='#')
            licz++;
        if(czy1 && czy2)
        {
            cout<<-1;
            return 0;
        }
        if(licz==0)
            row=true;
    }
    for(int y=0;y<b;y++)
    {
        int licz=0;
        bool czy1=false,czy2=false;
        for(int x=0;x<a-1;x++)
        {
            if(tab[x][y]=='.' && czy1==false)
                continue;
            if(tab[x][y]=='#' && tab[x+1][y]=='.')
                czy1=true;
            if(tab[x][y]=='.'&&tab[x+1][y]=='#')
                czy2=true;
            if(tab[x][y]=='#')
                licz++;
        }
        if(tab[a-1][y]=='#')
            licz++;
        if(czy1 && czy2)
        {
            cout<<-1;
            return 0;
        }
        if(licz==0)
            col=true;
    }
    if(row^col)
    {
        cout<<-1;
        return 0;
    }
    int licz=0;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            if(odw[x][y]==false && tab[x][y]=='#')
            {
                dfs(x,y,a,b);
                licz++;
            }
        cout<<licz;

	return 0;
}