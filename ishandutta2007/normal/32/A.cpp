//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define oo 0xBADC0DE
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define fill(a,v) memset(a, v, sizeof a)
#define ull unsigned long long
#define ll long long
#define bitcount __builtin_popcount
#define all(x) x.begin(), x.end()
#define pb( z ) push_back( z )
#define gcd __gcd
using namespace std;
typedef pair<int,int> point;
#define x first
#define y second


int a[1001],n,d,ctr;

int main()
{  
      s(n);s(d);
      for(int i=0;i<n;i++)s(a[i]);
      ctr=0;
      for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)
          //  if(a[i]==a[j])ctr++;
            //else
             if(abs(a[i]-a[j])<=d)ctr+=2;
      printf("%d\n",ctr);
//      system("PAUSE");
      return 0;
}