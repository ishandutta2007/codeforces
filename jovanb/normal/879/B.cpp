#include <bits/stdc++.h>

using namespace std;
int pobede[500];
int power[500];
int main()
{
    int n,brojac=0,j,lampa,i;
    long long k;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>power[i];
    }

    for(i=0;i<n;i++){
            brojac=0;
            lampa=0;
        for(j=i-1;j>=0;j--){
            if(power[i]<power[j])lampa=1;
            if(j==0)brojac=1;
        }
        if(lampa==0){
            for(j=i+1;j<n;j++){
                if(power[i]>power[j])brojac++;
                else break;
                if(brojac>=k){cout<<power[i];return 0;}
        }
            }
                }
    cout<<n;
    return 0;
}