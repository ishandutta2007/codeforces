#include<bits/stdc++.h>
using namespace std;
int tab[105][105];
int xd[105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>xd[x];
        for(int y=0;y<xd[x];y++)
        {
            cin>>b;
            tab[x][b]=1;
        }
    }
    for(int x=0;x<103;x++)
    {
        bool czy=false;
        for(int y=0;y<a;y++)
            if(tab[y][x]==0)
                czy=true;
        if(czy==false)
            cout<<x<<" ";
    }
	return 0;
}