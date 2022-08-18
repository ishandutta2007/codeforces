#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long long a,b,c;
int main(){
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);)answ=max(answ,ans[i]);
cin>>a>>b>>c;
a=a/c+(a%c>0);
b=b/c+(b%c>0);
cout<<a*b<<endl;
cin.get();cin.get();cin.get();
return 0;
}