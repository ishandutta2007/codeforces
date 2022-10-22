#include <bits/stdc++.h>
using namespace std;

long long niz[100];
long long price[6];
long long bot[6];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n;
    long long bal=0,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    for(i=1;i<=5;i++)cin>>price[i];
    for(i=0;i<n;i++){
        bal+=niz[i];
        for(j=5;j>=1;j--){
            bot[j]+=bal/price[j];
            bal%=price[j];
        }
    }
    for(i=1;i<=5;i++)cout<<bot[i]<<" ";
    cout<<"\n"<<bal;
    return 0;
}