#include <bits/stdc++.h>
using namespace std;
vector<long long> sas[700000];
vector<long long> ses[700000];
int main(){
    long long N,a;
    long long m=0;
    long long k =0;
    cin>> N;
    long long b[N];
    for(long long i = 0; i < N; i++){
        cin >> a;
        b[i]=a;
        if(a-i<0){ses[i-a].push_back(i);}
        else sas[a-i].push_back(i);
    }
    for(long long i = 0; i < 700000; i++){
        k = 0;
        for(auto x: sas[i])k+=b[x];
        m=max(k,m);
        k = 0;
        for(auto x: ses[i])k+=b[x];
        m = max(k,m);
    }
    cout << m;
    return 0;
}