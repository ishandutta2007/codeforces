#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair                                                        
#define ll long long

using namespace std;
map< ll , ll > mp;
ll n,a[1234567],b[12345678],z,m;

int main(){
   cin>>n>>m;
   while(m){
       if (m%n==0) {} else 
       if (m%n==1) {} else 
       if (m%n==n-1) m++; else {
           cout<<"NO"; return 0;
       }
       m/=n;
   } 
   cout<<"YES";

    return 0;
}