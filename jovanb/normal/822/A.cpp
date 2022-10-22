#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long br=1,i,a,b;
    cin>>a>>b;
    for(i=2;i<=min(a,b);i++){
        br*=i;
    }
    cout<<br;
    return 0;
}