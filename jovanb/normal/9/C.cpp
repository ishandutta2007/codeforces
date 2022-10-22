#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,i,x,r,g=0;
    cin>>n;
    x=0;
    for(i=1;x<=n;i++){
        r=i;
        x=0;
        g=-1;
        while(r!=0){
            g++;
            if(r%2==0){x+=0;}
            else x+=pow(10,g);
            r/=2;
        }
    }
    cout<<i-2;
    return 0;
}