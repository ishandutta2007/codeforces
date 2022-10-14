#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair <ll,ll> pll;

int N,M,T,i;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        if (N%M == 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}