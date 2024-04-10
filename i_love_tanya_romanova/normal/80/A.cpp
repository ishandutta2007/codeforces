#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
long n,m;
bool prime(long n)
{for (int i=2;i<n;i++)if (n%i==0)return false;
return true;}
bool prov()
{for (int i=n+1;i<m;i++)if (prime(i))return false;
if (!prime(m))return false;
return true;
 }
 int main(){
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);)answ=max(answ,ans[i]);
cin>>n>>m;
if (prov())cout<<"YES"<<endl; else cout<<"NO"<<endl;
cin.get();cin.get();cin.get();
return 0;
}