#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{

    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    if(n<31){cout<<"NO\n";continue;}
    n-=30;

    cout<<"YES\n";
    if(n!=6&&n!=10&&n!=14)
    cout<<6<<" "<<10<<" "<<14<<" "<<n<<endl;
    else cout<<6<<" "<<10<<" "<<15<<" "<<n-1<<endl;
}
    return 0;
}