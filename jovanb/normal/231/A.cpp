#include <iostream>
using namespace std;
int niz[10000];
int main() {
	// code goes into bulja
    int n,i,x,j;
    cin>>n;
    for(i=0;i<n;i++)
   for(j=0;j<3;j++){
    cin>>x;
    niz[i]+=x;
}
  x=0;
for(i=0;i<n;i++)if(niz[i]>=2)x++;
cout<<x;
	return 0;
}