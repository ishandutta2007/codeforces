#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long a,b,c,q,ans,p;
int main(){
  //  freopen("C:/input.txt","r",stdin);
   // freopen("C:/output.txt","w",stdout);
   cin>>a>>b>>c;
   q=a%2+a/2;p=1;
   if (b%2+b/2>=q){q=b%2+b/2;p=2;}
   if (c%2+c/2>=q){q=c%2+c/2;p=3;}
   ans=(q-1)*3+1*(p-1)+30;
   cout<<ans<<endl;
   
cin.get();cin.get();cin.get();
return 0;
}