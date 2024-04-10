#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 1){cout << "0\n"; continue;}
        int ans = 1;
        if(N % 2 == 1)ans++;
        if(N > 3)ans++;
        cout << ans <<"\n";
    }
    return 0;
}