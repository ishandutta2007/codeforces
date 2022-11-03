#include <iostream>
using namespace std;
int main(){
   int x,y,z,t,ans,n1,n2,p1,p2;
   cin >> x >> y >> z >> t;
   if((x+y)%2!=0) y++;
   if((z+t)%2!=0) t++;
   p1 = ((y-x)%2==0 ? (t-y+2)/2 : (t-y+1)/2);
   p2 = t-y+1-p1;
   n1 = (z-x+2)/2;
   n2 = (z-x+1)-n1;
   //cout << p1 << endl << p2 << endl << n1 << endl << n2 << endl;
   cout << p1*1LL*n1+p2*1LL*n2;
   return 0;
}