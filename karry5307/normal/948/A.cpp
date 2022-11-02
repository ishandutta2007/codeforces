#include<bits/stdc++.h>
using namespace std;
typedef int ll;
char mp[505][505];
ll length,width,vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};
int main()
{
    cin>>length>>width;
    for(register int i=1;i<=length;i++)
    {
        for(register int j=1;j<=width;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(register int i=1;i<=length;i++)
    {
        for(register int j=1;j<=width;j++)
        {
            if(mp[i][j]=='S')
            {
                for(register int k=0;k<4;k++)
                {
                    if(mp[i+vx[k]][j+vy[k]]=='W')
                    {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
            else
            {
                mp[i][j]=='.'?mp[i][j]='D':mp[i][j];
            }
        }
    }
    cout<<"Yes"<<endl;
    for(register int i=1;i<=length;i++)
    {
        for(register int j=1;j<=width;j++)
        {
            cout<<mp[i][j];
        }
        cout<<endl;
    }
}