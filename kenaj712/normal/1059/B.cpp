#include<bits/stdc++.h>
using namespace std;
bool czy[1005][1005];
bool odw[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    char znak;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            cin>>znak;
            if(znak=='#')
                czy[x][y]=true;
        }
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            if(czy[x][y]==true&&czy[x+1][y]==true&&czy[x+2][y]==true&&czy[x][y+1]==true&&czy[x][y+2]==true&&czy[x+2][y+1]==true&&czy[x+1][y+2]==true&&czy[x+2][y+2]==true)
            {
                odw[x][y]=true;
                odw[x+1][y]=true;
                odw[x+2][y]=true;
                odw[x][y+1]=true;
                odw[x][y+2]=true;
                odw[x+2][y+1]=true;
                odw[x+1][y+2]=true;
                odw[x+2][y+2]=true;
            }
        }
    bool ok=false;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            if(czy[x][y]==true&&odw[x][y]==false)
                ok=true;
    if(ok==false)
        cout<<"YES";
    else
        cout<<"NO";


	return 0;
}