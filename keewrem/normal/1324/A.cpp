#include <bits/stdc++.h>
using namespace std;
int t,N;
int k [1000];
int main(){
    cin >> t;
    while(t--){
        cin >> N;
        bool q = 0;
        for(int i = 0; i < N; i++)cin >> k[i];
        for(int i = 1; i < N; i++)if(k[i]%2!=k[i-1]%2)q=1;
        if(q)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}