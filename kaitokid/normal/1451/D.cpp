#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int d[30],r[30];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;
cin>>t;
while(t--)
{
   double d,k;
cin>>d>>k;
 double u=sqrt(k*k+k*k);
ll v=(d/u);
double g=v*k;
 double s=sqrt(g*g+(g+k)*(g+k));

if(s<=d)cout<<"Ashish\n";
else cout<<"Utkarsh\n";
}
    return 0;
}