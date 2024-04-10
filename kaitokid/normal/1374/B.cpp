#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,x,y;

int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)

{
    cin>>n;
    ll u=0,v=0;
    while(n%2==0){u++;n/=2;}
    while(n%3==0){v++;n/=3;}
    if(n!=1||u>v){cout<<-1<<endl;continue;}
    cout<<(v-u)+v<<endl;
}    return 0;
}