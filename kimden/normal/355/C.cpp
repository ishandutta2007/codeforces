#include <bits/stdc++.h>
using namespace std;

int main(){
   int n,l,r,ql,qr,x;
   cin >> n >> l >> r >> ql >> qr;
   int mn,cur=0,add;
   int w[100002];
   for(int i=0;i<n;i++){
      cin >> w[i];
      cur += w[i]*r;
   }
   x = -1;
   if(x+1==n-1-x){
      add = 0;
   }else{
      if(x+1<n-1-x){
         add = (n-3-2*x)*qr;
      }else{
         add = (2*x+1-n)*ql;
      }
   }
   mn = cur+add;
 //  cout << cur << "\t" << add << "\t" << cur+add << "\n";
 /*  left = x+1;
   right = n-1-x; */
   for(x=0;x<n;x++){
      cur += w[x]*(l-r);
      if(x+1==n-1-x){
         add = 0;
      }else{
         if(x+1<n-1-x){
            add = (n-3-2*x)*qr;
         }else{
            add = (2*x+1-n)*ql;
         }
      }
     // cout << cur << "\t" << add << "\t" << cur+add << "\n";
      mn = min(mn,cur+add);
   }
   cout << mn;
   return 0;
}