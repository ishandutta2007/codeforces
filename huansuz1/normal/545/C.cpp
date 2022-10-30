#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

 using namespace std;
 long long s,x[123457],y[123456],z=1,n;
 int main(){
    cin>>n;

 for (int i=0; i<n; i++)
    cin>>x[i]>>y[i];

 if (n<3) {cout<<n; return 0;} 
 
 for (int i=1; i<n-1; i++){
    if (x[i]-y[i]>x[i-1]) {z++; } else 
        if (x[i]+y[i]<x[i+1]) {x[i]+=y[i]; z++;}
 }
 z++;
 cout<<z;
 





    return 0;
 }