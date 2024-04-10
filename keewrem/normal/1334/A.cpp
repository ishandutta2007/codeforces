#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,T,K;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int c,p,a,b;
        N--;
        bool sos = 0;
        cin >> a >> b;
        if(a < b)sos = 1;
        while(N--){
            cin >> c >> p;
            if(c < p || c - a < p - b || c < a || p < b){
                sos = 1;
            }
            a = c; b = p;
        }
        if(sos )cout <<"NO\n";
        else cout << "YES\n";
    }
    return 0;
}