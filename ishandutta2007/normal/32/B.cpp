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

char code[201];
int num[201];
int main()
{  
      scanf("%s",code);
      int j=0,i=0;
      while(code[i]!='\0')
      { 
        if(code[i]=='.'){num[j]=0;j++;i++;}
        else if(code[i]=='-' && code[i+1]=='.'){num[j]=1;j++;i+=2;}
        else if(code[i]=='-' && code[i+1]=='-'){num[j]=2;j++;i+=2;}
      }
      for(i=0;i<j;i++)
        printf("%d",num[i]);printf("\n");
//      system("PAUSE");
      return 0;
}