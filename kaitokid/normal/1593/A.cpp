#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {

    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(0,max(b,c)-a+1)<<" "<<max(0,max(c,a)-b+1)<<" "<<max(0,max(b,a)-c+1)<<endl;
    }
    return 0;
}