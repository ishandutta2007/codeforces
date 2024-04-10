#include <iostream>
#include<algorithm>

using namespace std;

int x[5],y[5],a[5],b[5],n,ans,x2,y2;

int dis(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

bool check()
{
    if(dis(0,1)==0 || dis(1,2)==0 || dis(2,3)==0 || dis(0,2)==0 || dis(0,3)==0 || dis(1,3)==0)
        return false;
    if(dis(0,1)==dis(0,2) && dis(0,1)==dis(2,3) && dis(0,1)==dis(1,3) && dis(0,3)==dis(1,2))
        return true;
    if(dis(0,1)==dis(0,3) && dis(0,1)==dis(2,3) && dis(0,1)==dis(1,2) && dis(0,2)==dis(1,3))
        return true;
    if(dis(0,3)==dis(0,2) && dis(0,2)==dis(2,1) && dis(0,2)==dis(1,3) && dis(0,1)==dis(3,2))
        return true;
    return false;
}

void turn(int i)
{
    x2=y[i]-b[i];
    y2=x[i]-a[i];
    if(y2>0 && x2>=0)
    {
        x[i]=a[i]-abs(x2);
        y[i]=b[i]+abs(y2);
    }
    if(y2<=0 && x2>0)
    {
        x[i]=a[i]-abs(x2);
        y[i]=b[i]-abs(y2);
    }
    if(y2<0 && x2<=0)
    {
       // if(i==3)
      //      cout<<"*"<<i<<endl;
        x[i]=a[i]+abs(x2);
        y[i]=b[i]-abs(y2);
    }
    if(y2>=0 && x2<0)
    {
        x[i]=a[i]+abs(x2);
        y[i]=b[i]+abs(y2);
    }
}

int main()
{
    cin>>n;
    for(int q=0;q<n;q++)
    {
        for(int i=0;i<4;i++)
            cin>>x[i]>>y[i]>>a[i]>>b[i];
        ans=1000000;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int u=0;u<4;u++)
                {
                    for(int v=0;v<4;v++)
                    {
                     //   cout<<v<<" "<<x[3]<<" "<<y[3]<<endl;
                        if(check())
                        {
                       //     cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
                     //       for(int j=0;j<4;j++)
                     //           cout<<x[j]<<" "<<y[j]<<endl;
                            ans=min(ans,i+j+v+u);
                   //         return 0;
                        }
                        turn(3);
                    }
                    turn(2);
                }
                turn(1);
            }
            turn(0);
         //   for(int j=0;j<4;j++)
          //      cout<<x[j]<<" "<<y[j]<<endl;
           // cout<<"#"<<endl;
        }
        if(ans>10000)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}