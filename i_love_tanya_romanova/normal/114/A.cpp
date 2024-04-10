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
long long n,k,s;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>k>>n;
while (n%k==0)
{n/=k;s++;
      }
      --s;
if (n>1)cout<<"NO"<<endl;
else {cout<<"YES"<<endl;cout<<s<<endl;}

cin.get();cin.get();
return 0;
}