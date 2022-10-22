#include <bits/stdc++.h>

using namespace std;
double limit[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,j,i;
    long r,x;
    double v;
    cin>>n>>r;
    for(i=1;i<=1000;i++)limit[i]=r;
    for(i=0;i<n;i++){
        cin>>x;
        cout<<fixed<<setprecision(7)<<limit[x]<<endl;
        v=limit[x];
        for(j=max(long(1),x-2*r);j<=min(long(1000),x+2*r);j++){
            limit[j]=max(limit[j],double(sqrt(double(4*r*r-(j-x)*(j-x)))+v));
            //cout<<j<<" "<<limit[j]<<" ";
        }
        //cout<<endl<<endl;
    }
    return 0;
}