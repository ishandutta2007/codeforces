#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,x,y,x1,y1;
    bool mark[10][10],ans;
    cin>>t;
    for(int u=0;u<t;u++)
    {
        for(int i=1;i<10;i++)
            for(int j=0;j<10;j++)
            {
                mark[i][j]=false;
            }
        x=0;y=0;x1=0;y1=0;
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
            {
                char c;
                cin>>c;
                if(c=='#')
                    mark[i][j]=true;
                else if(c=='K')
                {
                    if(x==0)
                    {
                        x=i;y=j;
                    }
                    else
                    {
                        x1=i;y1=j;
                    }
                }
            }
        ans=false;
        if(max(x1-x,x-x1)%4==0 && max(y1-y,y-y1)%4==0)
        {
            for(int i=1;i<=8 && ans==false;i++)
                for(int j=1;j<=8 && ans==false;j++)
                    if((max(i-x,x-i)+max(j-y,y-j))%4==0 && mark[i][j]==false)
                    {
                        cout<<"YES"<<endl;
                        ans=true;
                        break;
                    }
        }
        if(ans==false)
            cout<<"NO"<<endl;
    }
}