#include <bits/stdc++.h>

using namespace std;

int main()
{
 ios::sync_with_stdio(0);
 int a,b,c,d,k,t;
 cin>>t;
 while(t--)
 {
     cin>>a>>b>>c>>d>>k;
     int ans=(c+a-1)/c;
int ans1=(b+d-1)/d;
if(ans+ans1>k){cout<<-1<<endl;continue;}
cout<<ans<<" "<<ans1<<endl;
 }
    return 0;
}