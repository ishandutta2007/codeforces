#include <bits/stdc++.h>

using namespace std;
long long mani[100005];
int main()
{
    long n,i,br=0;
    long long zb=0,d;
    cin>>n>>d;
    for(i=0;i<n;i++){
        cin>>mani[i];
        zb+=mani[i];
        if(mani[i]==0 && zb<0)zb=0;
        if(zb>d){cout<<-1;return 0;}
    }
    zb=0;
    for(i=0;i<n;i++){
        zb+=mani[i];
        zb=min(d,zb);
        if(mani[i]==0){
            if(zb<0){
                zb=d;
                br++;
            }
        }


    }
    cout<<br;
    return 0;
}