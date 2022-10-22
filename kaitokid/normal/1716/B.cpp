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

 int n;
 cin>>n;
 cout<<n<<endl;
 for(int i=n;i>=1;i--)
 {
     int d=1;
     for(int j=1;j<=n;j++)
        if(j==i)cout<<n<<" ";
     else cout<<(d++)<<" ";
     cout<<endl;
 }
 }
    return 0;
}