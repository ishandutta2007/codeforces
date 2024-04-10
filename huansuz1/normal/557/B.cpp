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

int n,a[223456];
double ans,w;

int main(){
    cin>>n>>w;

    for (int i=0; i<n*2; i++)
        cin>>a[i];
    sort(a,a+(n*2));
    double kyz=a[0];
    double bal=a[n];
    double q=min(kyz,bal/2);
    if ((q*n)+((q+q)*n)<=w) printf("%.10lf",(q*n)+((q+q)*n)); else printf("%.10lf",w);


    return 0;
}