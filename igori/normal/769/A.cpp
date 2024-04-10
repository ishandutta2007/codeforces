#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m[10];
    for(int i=0; i<n; i++)
        cin>>m[i];
    sort(m,m+n);
    if(n==1)
        cout<<m[0];
    if(n==3)
        cout<<m[1];
    if(n==5)
        cout<<m[2];
}