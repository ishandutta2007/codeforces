#include<bits/stdc++.h>
using namespace std;
char mapa[105][105];
int liczba(char a)
{
    return int(a)-48;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            cin>>mapa[x][y];
            if(mapa[x][y]=='.')
                mapa[x][y]='0';
        }
    bool czy=false;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            if(mapa[x][y]!='*')
            {
            int pom=0;
            if(mapa[x-1][y]=='*')
                pom++;
            if(mapa[x-1][y-1]=='*')
                pom++;
            if(mapa[x-1][y+1]=='*')
                pom++;
            if(mapa[x][y-1]=='*')
                pom++;
            if(mapa[x][y+1]=='*')
                pom++;
            if(mapa[x+1][y-1]=='*')
                pom++;
            if(mapa[x+1][y]=='*')
                pom++;
            if(mapa[x+1][y+1]=='*')
                pom++;
            if(pom!=liczba(mapa[x][y]))
                czy=true;
            }
        }
    if(czy==true)
        cout<<"NO";
    else
        cout<<"YES";
	return 0;
}