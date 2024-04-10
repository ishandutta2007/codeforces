#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 sgjkdf
using namespace std;
long a,b,c,d;
bool ct(long a,long b)
{if (a>b+1)return false;
 if (a*2+2<b)return false;
 return true;
 }
int main(){
  //  freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

cin>>a>>b>>c>>d;

if (ct(a,d)||ct(b,c))cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();cin.get();
return 0;
}