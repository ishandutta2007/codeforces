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

ll m,n,ok[123],ans,l,r,x,a[102367],z;
void rec(int v){
    if (v>n) {
        long long s=0;
        if (ok[1]!=0) {
            for (int i=1; i<=n; i++)
                s=(s*10)+ok[i]; 
            if (s>0) a[z++]=s;
        }
        return;    
    }
    ok[v]=1;
    rec(v+1);
    ok[v]=0;
    rec(v+1);
}


int main(){   
cin>>m;
for (int i=1; i<=10; i++) {
    n=i;
    rec(1);                    
}
sort(a,a+z);
for (int i=0; i<z; i++){
    if (a[i]<=m) ans++; else break;
}
cout<<ans<<endl;




}