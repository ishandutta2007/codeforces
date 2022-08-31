#include <iostream>
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
using namespace std;
long long n,f,s,t,m,w,q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{cin>>s>>f>>t;

if (s==f)cout<<t<<endl;//negspyf

 if (f>s)
 {q=t%(m*2-2);w=t/(m*2-2);
  if (q>=s){cout<<(w+1)*(m*2-2)+f-1<<endl;}// xtrf'v lj yfcnegyjuj
  else cout<<w*(m*2-2)+f-1<<endl;}// ]ltv wbv
         
  if (f<s)
  {q=t%(m*2-2);w=t/(m*2-2);//cout<<w<<endl;
  if (q<=2*m-2-s+1)cout<<w*(m*2-2)+2*m-2-f+1<<endl;//ksan jgecnbnmcz s czltv
   else cout<<(w+1)*(m*2-2)+2*m-f-2+1<<endl;
          }

}
cin.get();cin.get();
return 0;
}