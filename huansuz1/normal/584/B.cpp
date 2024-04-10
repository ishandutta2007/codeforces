#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;

 long long n,m,q,k,a[1234],b[1234],c[1234],x,y,ma,p;


 int main(){
 cin>>n;
 q=1,k=1;
 for (int i=0; i<3*n; i++)
    q=(q*3)%1000000007;
 for (int i=0; i<n; i++)
    k=(k*7)%1000000007;
 cout<<(q-k+1000000007)%1000000007;


    
    
    
    
    
    return 0;
 }