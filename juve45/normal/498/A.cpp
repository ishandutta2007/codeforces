#include<iostream>
using namespace std;
long long x,X,y,Y,a,b,c,ans=0;
int n;
int main()
{
    cin>>x>>y>>X>>Y;
    cin>>n;
    for(int i=1;i<=n;i++)
      {
        cin>>a>>b>>c;
        if(a*x+b*y+c>0^a*X+b*Y+c>0)
          ans++;
      }
    cout<<ans<<'\n';
    return 0;
}