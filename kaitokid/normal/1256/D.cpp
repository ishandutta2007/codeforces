#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll q,n,k;
string s;
int main()
{
    ios::sync_with_stdio(0);
cin>>q;
while(q--)
{
    cin>>n>>k>>s;
 ll x=0;
 for(int i=0;i<n;i++)
 {
     if(s[i]=='1')continue;
     ll w=max(x,i-k);
     s[i]='1';
     s[w]='0';

     k-=(i-w);
     if(k<=0)break;
 x++;
 }
 cout<<s<<endl;
}
    return 0;
}