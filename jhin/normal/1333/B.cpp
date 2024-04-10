#include <bits/stdc++.h>

using namespace std;







int n,x,y,m,t;
int main()
{

    ios_base::sync_with_stdio(false);

cin>>t;
while(t--)
{
    cin>>n;
    int a[n],b[n],c[n];memset(c,0,sizeof c);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=1;i<n;i++)
    {
        if(a[i-1]==1)
        {
            if(c[i-1]==0)c[i]=1;
            else if(c[i-1]==2)c[i]=3;
            else if(c[i-1]==1)c[i]=1;
            else if(c[i-1]==3)c[i]=3;
        }
        else if(a[i-1]==-1)
        {
            if(c[i-1]==0)c[i]=2;
            else if(c[i-1]==1)c[i]=3;
            else if(c[i-1]==2)c[i]=2;
            else if(c[i-1]==3)c[i]=3;
            
        }
        else c[i]=c[i-1];

    }
    //for(int i=0;i<n;i++)cout<<c[i]<<" h";cout<<endl;
    bool yes=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]<b[i])
        {
            if(!(c[i]==1||c[i]==3))yes=false;
        }
        else if(a[i]>b[i])
        {
            if(!(c[i]==2||c[i]==3))yes=false;
        }
        //cout<<yes<<" ";
    }
    if(yes)cout<<"YES\n";
    else cout<<"NO\n";

}








    return 0;
}