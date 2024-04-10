#include <iostream> 
using namespace std; 
int main() { 
int n,a,t=0;
 cin>>n; 
for (;n>0;n--) {
cin>>a;
if (a==1) t=1;
} if (t==1) cout<<-1;
else cout<<1; 
return 0; }