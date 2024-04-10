#include <iostream>
using namespace std;
int a,b,c,n,z;
int main(){
cin>>n;

for (int i=0; i<n; i++){
cin>>a>>b>>c;
if (a+b+c >= 2) z++;
}
cout<<z;





}