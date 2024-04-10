#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N,K;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        if(N>=K*K && N%2==K%2)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}