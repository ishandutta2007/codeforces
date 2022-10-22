#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long long n,i;
    double h,p,p1,p2;
    cin>>n>>h;
    p=h/2;
    p1=p/n;
    p2=0;
    for(i=1;i<n;i++){
        p2+=p1;
        cout<<fixed<<setprecision(10)<<sqrt(2*p2*h)<<" ";
    }
    return 0;
}