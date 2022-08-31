#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long long l,a,ans,n;
bool isgod(long long a)
{l=0;
 while (a)
 {if (a%10==4)l++; else l--;a/=10;       }
if (l)return 0; else return 1;
}
void gener(long long a)
{
     if (isgod(a))
     {if (a>=n&&a<ans)ans=a;
                  }
                  if (a>1000000000)return;
     gener(a*10+4);gener(a*10+7);
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;

ans=1000000000;
ans*=100;

gener(4);
gener(7);
cout<<ans<<endl;
cin.get();cin.get();
return 0;}