#include <iostream>

using namespace std;
int n;
int main()
{
cin>>n;
int u;
for(int i=1;i<=n;i++)
{
     cin>>u;
int gf=180-u;
if(360%gf==0)
    cout<<"YES\n";
else cout<<"NO\n";
}


    return 0;
}