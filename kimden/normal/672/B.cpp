#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007

int main()
{
   int n;
   char c;
   map<char,int> mp;
   cin >> n;
   if(n>26){
      cout << -1;
      return 0;
   }
   for(int i=0;i<n;i++){
      c='\n';
      while(c=='\n') cin >> c;
      mp[c]++;
   }
   int k = 0;
   for(auto y:mp){
      k++;
   }
   cout << n-k;
   return 0;
}