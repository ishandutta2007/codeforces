// Hydro submission #62c7c53a8672efa577c0cbfe@1657259322818
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <deque>
#include <bits/stdc++.h>
#include <map>
#include <stack>
#include <numeric>
#include <algorithm> // for copy.
#include <iterator> // for back_inserter
#include <numeric>
#include <iostream> 
#define f(i,a,b) for(long long i=a;i<b;i++)
 
using namespace std;
 
 
 
signed main()
{
  ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
   long long n;cin>>n;
   long long a[n];
   long long p=0;
   for(long long i=0;i<n;i++)
   {
     cin>>a[i];p+=a[i];
   }
   sort(a,a+n);
   long long q;cin>>q;
   for(long long i=0;i<q;i++)
   {
     long long x,y;
     cin>>x>>y;
   
   long long l=0,r=n-1,d=-1;
   while(l<=r)
   {long long h=0;
     long long m=(l+r)>>1;
     long long f=a[m];
     long long c=p-f;
     long long e=max(x-f,h)+max(y-c,h);
     if(a[m]<x)
     { if(d==-1)
     d=e;
     if(d!=-1)
       d=min(d,e);l=m+1;
     }
     if(a[m]>=x)
     { if(d==-1)
     d=e;
     if(d!=-1)
       d=min(d,e);r=m-1;
     }
   }
   cout<<d<<endl;
   }}