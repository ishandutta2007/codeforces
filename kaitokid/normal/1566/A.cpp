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
        ll n,s;
        cin>>n>>s;
        n=n-(n+1)/2+1;
        cout<<s/n<<endl;
    }
    return 0;
}