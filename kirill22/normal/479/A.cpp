 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;

int n,m,k,sum=1,co=1;
string s,s1,s2="";
main() {
     cin >>m>> n >> k;
     sum=max(sum,m+n+k);
     sum=max(sum,m+n*k);
     sum=max(sum,(m+n)*k);
     sum=max(sum,m*n*k);
     sum=max(sum,m*n+k);
     sum=max(sum,m*(n+k));
     cout << sum;




}