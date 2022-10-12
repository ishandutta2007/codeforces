#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
  int before, after, delta, used;
} S;

bool f(S x, S y) {return x.delta > y.delta; }

int main() {
    int n,k;
    cin>>n>>k;
    S d[200000]={0};
    int minV=0, minK1=0, minK2 = 0;
    int ans=0;
    
    for(int i=0; i<n; i++)
       cin>>d[i].before;
       
    for(int i=0; i<n; i++) {
       cin>>d[i].after;
       int t = min(d[i].before, d[i].after);
       minV += t;
       if (t == d[i].before) {d[i].used = 1; minK1++; }
       else minK2++;
       
       d[i].delta = d[i].after - d[i].before;
       
    }
  
    //cout<<minV<<" "<<minK1<<" "<<minK2<<"\n";     
    if (minK1<k) {
          sort(d, d+n, f);
          for(int i=0; i<n; i++) {
               if (d[i].used) continue;
               //cout<<d[i].delta<<" "<<d[i].before<<" "<<d[i].after<<"\n";
               minK1++;
               minV += -d[i].delta;
               if (minK1>=k) break;
          }
    }
    cout<<minV;
}