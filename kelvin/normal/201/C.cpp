#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100050

using namespace std;

int n;
int s[MAXN];
long long sor0[MAXN],sor1[MAXN];
int f1l[MAXN],f1r[MAXN];
long long zl[MAXN],zr[MAXN];

void rev() {
   for(int i=0;i<n-i-1;i++)
      swap(s[i],s[n-i-1]);
}

long long lfirst() {
   sor0[n]=sor1[n]=0;
   for(int i=n-1;i>=0;i--) {
      sor0[i]=sor0[i+1]+s[i]-(s[i]&1);
      sor1[i]=sor1[i+1]+s[i]-(s[i]+1&1);
   }
   //
   f1l[n]=n;
   zr[n]=0;
   for(int i=n-1;i>=0;i--) {
      if(s[i]==1) f1l[i]=i;
      else f1l[i]=f1l[i+1];
      zr[i]=sor0[i]-sor0[f1l[i]];
   }
   f1r[0]=-1;
   zl[0]=0;
   for(int i=0;i<n;i++) {
      if(s[i]==1) f1r[i+1]=i;
      else f1r[i+1]=f1r[i];
      zl[i+1]=sor0[f1r[i]+1]-sor0[i+1];
   }
   //
   //int first1=n;
   long long opt=0;
   int j=n;
   for(int i=n;i>=0;i--) {
      //if(s[i]==1) first1=i;
      //long long val=(sor0[i]-sor0[first1])+(sor1[first1]-sor1[n]);
      long long val1=zl[i]+zr[j]+sor1[i]-sor1[j];
      long long val2=zl[i]+zr[i]+sor1[i]-sor1[i];
      if(val2>val1) j=i;
      opt=max(max(opt,val1),val2);
   }
   return opt;
}

/*long long rfirst() {
   rev();
   long long val=lfirst();
   rev();
   return val;
}*/

long long solve() {
   //return max(lfirst(),rfirst());
   return lfirst();
}

int main(void)
{
   scanf("%d",&n);
   n--;
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   cout << solve() << endl;
   return 0;
}