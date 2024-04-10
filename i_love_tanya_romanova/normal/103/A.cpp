#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 aasdfasdfasdf
using namespace std;
long long n,ans,ar[100000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];ans+=(ar[i]-1)*(i);}
cout<<ans+n<<endl;
cin.get();cin.get();cin.get();
return 0;
}