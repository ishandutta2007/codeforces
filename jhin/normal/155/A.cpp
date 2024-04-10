#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool str[1000];int cnt,n,k,a[1000],j=1,mx,mn;
int main()
{
   cin>>n>>k;mx=k;mn=k;
   for(int i=1;i<n;i++){cin>>k;if(k>mx||k<mn)cnt++;mx=max(k,mx);mn=min(k,mn);}
   cout<<cnt;

    return 0;
}