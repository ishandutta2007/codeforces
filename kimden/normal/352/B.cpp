#include <bits/stdc++.h>
using namespace std;

struct my_pair {
  pair<int,int> p;
  my_pair(int last=-1,int sub=0){
     p.first = last;
     p.second = sub;
  }
};

int main(){
   map<int,my_pair> m;
   int n;
   int a;
   int sub;
   int cnt=0;
   cin >> n;
   for(int i=0;i<n;i++){
      cin >> a;
      if(m[a].p.first==-1){
         m[a] = my_pair(i);
         cnt++;
      }else{
         sub = i-m[a].p.first;
         if(m[a].p.second!=-1){
            if(m[a].p.second==0){
               m[a] = my_pair(i,sub);
            }else{
               if(m[a].p.second==sub){
                  m[a] = my_pair(i,sub);
               }else{
                  m[a] = my_pair(i,-1);
                  cnt--;
               }
            }
         }
      }
   }
   cout << cnt << "\n";
   for(auto x: m){
      if(x.second.p.second!=-1){
         cout << x.first << " " << x.second.p.second << "\n";
      }
   }
   return 0;
}