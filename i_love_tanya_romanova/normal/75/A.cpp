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
long long a,b,r,s,q,rr;
int main(){
  //  freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
cin>>a>>b;
q=0;
r=a+b;

while (a){if (a%10!=0)q=q*10+a%10;a/=10;}
while (q){a=a*10+q%10;q/=10;}
while (b){if (b%10!=0)q=q*10+b%10;b/=10;}
while (q){b=b*10+q%10;q/=10;}

rr=a+b;
//cout<<r<<" "<<rr<<endl;
while (r){if (r%10!=0)q=q*10+r%10;r/=10;}
while (q){r=r*10+q%10;q/=10;}
//cout<<r<<endl;
if (r==rr)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin.get();cin.get();cin.get();
return 0;
}