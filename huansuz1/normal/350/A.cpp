#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,m,a=1002,b,c=1002,x;
long long mod=1000000007;   


int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>x;             
        a=min(a,x);
        b=max(b,x); 
    }
    for (int i=0; i<m; i++){
        cin>>x;
        c=min(c,x);
    }
    if (max(2*a,b)<c) cout<<max(2*a,b); else cout<<-1;



    return 0;
}