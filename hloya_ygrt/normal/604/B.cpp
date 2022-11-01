#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <deque>

#include <list>
#include <stdio.h>
#include <string>

const int maxn=2e5;
const int inf=2e9;
const int eps=1e-9;
const int minf=-2e9;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
                                                                                                                                                                                                                                                            #define int long long
#define ld long double

#define forn() for(int i=0;i<n;i++)
#define nfor() for(int i=n-1;i>=0;i--)

using namespace std;
deque<int> s;
main()
{
   int n,k;
   int ans=-2e9;
   scanf("%I64d %I64d",&n,&k);

   for(int i=0;i<n;i++)
   {
       int x;
       scanf("%I64d",&x);
       s.pb(x);
   }

   while (n!=2*k&&!s.empty())
   {
       ans=max(ans,s.back());
       n--;
       k--;
       s.pop_back();
   }

   while (!s.empty())
   {
       int t=s.front()+s.back();
       ans=max(t,ans);
       s.pop_back();
       s.pop_front();
   }
   printf("%I64d",ans);
    return 0;
}