#include <bits/stdc++.h>
using namespace std;

int main (){
ios::sync_with_stdio(0);
int n,k;
cin>>n>>k;
cout<<min(1,min(n-k,k))<<" "<<min(n-k,2*k);

return 0;}