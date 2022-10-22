#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,x[2],y[2];
    cin>>t;
    while(t--)
    {
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        if(x[0]==x[1])cout<<abs(y[1]-y[0])<<endl;
        else if(y[0]==y[1])cout<<abs(x[0]-x[1])<<endl;
    else cout<<abs(y[1]-y[0])+abs(x[0]-x[1])+2<<endl;
    }
    return 0;
}