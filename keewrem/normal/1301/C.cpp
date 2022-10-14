#include <bits/stdc++.h>
using namespace std;
int sas[100000];
int main(){
    int T;
    unsigned long long N,M,k,p,res;
    cin>>T;
    while(T--){
        cin >> N >> M;
        k = (N-M)%(M+1);
        p = (N-M)/(M+1);
        res = ((p*(p-1))/2+p)*(M+1-k)+(((p+1)*p)/2+p+1)*k;
        cout << (N*(N-1))/2+N - res << "\n";
    }
    return 0;
}