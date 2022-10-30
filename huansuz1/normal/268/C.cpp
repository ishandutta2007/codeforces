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

int z,n,m,ma,x[123],y[123],a[123],ans;


int main(){
    cin>>n>>m;
    for (int i=min(n,m); i>=0; i--) {
            x[ans]=z; 
            y[ans]=i; 
            ans++; 
            z++;
    }
    cout<<ans<<endl;
    for (int i=0; i<ans; i++)
        cout<<x[i]<<" "<<y[i]<<endl;





    return 0;
}