#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
//IgorI
//It is true or false
//Is it true or false?

   
int main()
{
   cin(b1);
   cin(q);
   cin(l);
   cin(mc);
   int m[1000000] = {0};
   int mm[1000000] = {0};
   bool b1notm = true;
   bool mb1notm = true;
   bool zeronotm = true;
   int k =0;
   for(int i=0; i<mc; i++) {
        cin>>m[i];
        //if (m[i]==1000000000) { cout<<"!!"; return 0;}
        if (m[i]==b1) b1notm = false;
        if (m[i]==-b1) mb1notm = false;
        if (m[i]==0) zeronotm = false;
        if ((abs(m[i])<=l) && (b1 && m[i]%b1==0)) { 
             int qq = m[i]/b1;
             if ((qq!=1) && q && (qq%q !=0)) continue;

             bool found=false;
             for (int j=0;j<k;j++) {
               if (mm[j]==m[i]) { found=true; break; }
             }
             if (!found) { mm[k] = m[i]; k++; }
        }
   }
   if (abs(b1)>l) {
     cout<<0;
     return 0;
   }
   if(q==0)   { // one b1 or inf of "0" or 0
     if ((0<=l) && zeronotm) { cout<<"inf"; return 0; }
     if ((abs(b1)<=l) && b1notm) { cout<<1; return 0; }
     cout<<0;
     return 0;
   }
   if(q==1)   { // 0 or inf of "b1"
     if ((abs(b1)<=l) && b1notm) { cout<<"inf"; return 0; }
     cout<<0;
     return 0;
   }
   if(q==-1) { // 0 or inf of "b1" or "-b1"
     if ((abs(b1)<=l) && b1notm) { cout<<"inf"; return 0; }
     if ((abs(-b1)<=l) && mb1notm) { cout<<"inf"; return 0; }
     cout<<0;
     return 0;
   }
   if(b1==0)  { // 0 or inf of "0"
     if ((0<=l) && zeronotm) { cout<<"inf"; return 0; }
     cout<<0;
     return 0;
   }

   sort(mm, mm+k);

   int ans=0;
   int iter=0;
   while (abs(b1)<=l) {
        bool bad = false;
        //if (b1>=mm[0] && ((k==0) || (b1<=mm[k-1]))) {
          for (int i=1; i<=k; i++) {
               iter++;
               if (mm[i-1]==b1) { bad = true; break; }
          }
        //}
        if (!bad) ans++;
        if (b1==l) break;
        b1 = b1*q;
   }
   cout <<ans;//<<" "<<iter<<" "<<k;
}