#include <bits/stdc++.h>

using namespace std;
#define DIM 100000007.0
typedef pair<long long,long long> pairll;
long long d,l,r,m,t;
int main()
{
    cin>>t;
    for (int i = 0;i<t;i++){
    cin>>l>>r>>d;
    m = d;
    if (d<l)cout<<d<<endl;
    else{
        cout<<r-r%d+d<<endl;
    }
    }
}