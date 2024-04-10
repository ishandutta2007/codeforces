#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,y,x;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    y^=x;
}
if(n%2==0&&y!=0){cout<<"NO";return 0;}
cout<<"YES\n";

int i;
int ans=n;
cout<<n<<endl;
for(i=1;i+2<=n;i+=2)
{
cout<<i<<" "<<i+1<<" "<<i+2<<endl;
ans--;
}
for(i;i-2>0;i-=2)
  {cout<<i-2<<" "<<i-1<<" "<<i<<endl;
  ans--;
  }
  while(ans--)
    cout<<1<<" "<<2<<" "<<3<<endl;
    return 0;
}