#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,n,k;
cin>>t;
while(t--)
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cout<<char('a'+(i%3));
    }
    cout<<endl;
}
    return 0;
}