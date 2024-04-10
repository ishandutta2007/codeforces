#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
   ll q, n, r1, r2, r3, c;
   set<ll>s;
   vector<ll>v;
   cin >> q;
   while(q--){
      cin >> n;
      r1=0;r2=0;r3=0;
      v.clear();
      s.clear();
      for(int i=0; i<n; i++){
         cin >> c;
         if(*s.lower_bound(c)!=c){
            s.insert(c);
            v.push_back(c);
         }
      }
      sort(v.begin(), v.begin()+v.size());
      r1=v[v.size()-1];
      c=0;
      for(int i=v.size()-1; i>=c; i--){

         for(int t=i-1; t>=c; t--){

            if(v[i]%v[t]!=0){

               if(v[i]+v[t]>r2)r2=v[i]+v[t];

               for(int j=t-1; j>=c; j--){
                  if(v[i]%v[j]!=0&&v[t]%v[j]!=0){

                     if(v[i]+v[t]+v[j]>r3){
                        r3=v[i]+v[t]+v[j];
                        c=j;
                     }
                  }
               }
            }
         }
      }
      cout << max(max(r1, r2), r3) << "\n";
   }
}