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

int k,n,w,a[1234],s;
                      
int main(){
cin>>k>>n>>w;
a[0]=k;
s=k;
for (int i=1; i<w; i++) {
    a[i]=a[i-1]+k;       
    s+=a[i];    
}
if (s<=n) cout<<0; else cout<<s-n;



            return 0;


}