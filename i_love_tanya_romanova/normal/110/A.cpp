#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long long n,s,q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;s=0;
while (n)
{q=n%10;n/=10;
 if (q==4||q==7)s++;
      }
 if (s==4||s==7)cout<<"YES"<<endl; else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;
}