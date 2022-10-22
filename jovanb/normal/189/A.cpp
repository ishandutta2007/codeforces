#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,a,b,c,n,maxres=0;
    cin>>n>>a>>b>>c;
    for(i=0;i<=n;i+=a){
        for(j=0;j<=n-i;j+=b){
                if((n-i-j)%c==0)maxres=max(maxres,i/a+j/b+(n-i-j)/c);
        }
    }
    cout<<maxres;
    return 0;
}