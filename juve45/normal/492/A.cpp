#include <iostream>
using namespace std;
int n, i=1, k=1;
int main(){cin>>n;
while(n>=0) n-=i,k++,i+=k;
cout<<k-2;return 0;}