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
long n;
string st[20000];
int main(){
  //  freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
{cin>>st[i];
}
sort(st,st+n);
if (st[(n+1)/2-1]!=st[0])cout<<st[(n+1)/2-1]<<endl;
else cout<<st[0]<<endl;
cin.get();cin.get();cin.get();
return 0;
}