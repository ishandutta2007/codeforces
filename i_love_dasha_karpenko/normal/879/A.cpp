#include <bits/stdc++.h>

using namespace std;
long long n,day = 0;
int main()
{

    cin>>n;
    for (int i = 1;i<=n;i++){
        long long x,y; cin>>x>>y;
        while(x<=day)x+=y;
        day = x;
    }
    cout<<day<<endl;
}