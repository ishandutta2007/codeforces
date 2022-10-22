#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,ans=0,co=0;
   cin >> n;
   vector<pair<int,int> > a(n);
   for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;

   }
   int k;
   cin >> k;
   int ii=0;
   while(ii<n && a[ii].second<k){
    ii++;
   }
   cout << n-ii;
}