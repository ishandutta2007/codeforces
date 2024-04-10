#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

 using namespace std;
 long long s,a[123456],n,z=1;
 map<long long,long long> m;
 int main(){
    cin>>n;
 for (int i=0; i<n; i++)
    cin>>a[i];
 sort(a,a+n);

 s=a[0];
 for (int i=1; i<n; i++){
    if (s<=a[i]) {z++; s+=a[i]; }
 }
 cout<<z;




    return 0;
 }