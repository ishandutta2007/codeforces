#include <bits/stdc++.h>

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
   cout<<1;
   for(int i=0;i<a-1;i++)cout<<0;
   cout<<" ";
   int u=b-c+1;
   for(int i=0;i<u;i++)cout<<1;
   for(int i=0;i<c-1;i++)cout<<0;
    cout<<endl;

    }
    return 0;
}