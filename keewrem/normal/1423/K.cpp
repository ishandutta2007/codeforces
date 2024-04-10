#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mn = 1000010;
bool p[mn];
ll T,N;
ll kek[mn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    kek[1]=1;
    for(ll i = 2; i < mn; i++){
        kek[i]+=kek[i-1];
        if(p[i])continue;
        for(int j = 2*i; j < mn; j+=i)p[j]=1;
        kek[i]++; if(i*i<mn)kek[i*i]--;
        
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << kek[N]<<"\n";
    }
    return 0;
}