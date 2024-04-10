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
int n;
long long a[123456];

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    cout<<a[1]-a[0]<<" "<<a[n-1]-a[0]<<endl;
    for (int i=1; i<n-1; i++)
        cout<<min(a[i]-a[i-1],a[i+1]-a[i])<<" "<<max(a[i]-a[0],a[n-1]-a[i])<<endl;
    cout<<a[n-1]-a[n-2]<<" "<<a[n-1]-a[0];


    return 0;
}