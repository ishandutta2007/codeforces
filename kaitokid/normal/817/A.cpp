#include <iostream>

using namespace std;

int main()
{
int a,b,a2,b2,x,y;
cin>>a>>b>>a2>>b2>>x>>y;
int u=max(b2,b)-min(b2,b);
int s=max(a2,a)-min(a2,a);
if(u%y==0&&s%x==0){
     if((u/y)%2==(s/x)%2)
       {cout<<"YES";

        return 0;}}
    cout<<"NO";
    return 0;
}