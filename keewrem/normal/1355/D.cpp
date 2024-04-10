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
ll N,S;

int main(){
    cin >> N >> S;
    if(S < 2*N){cout << "NO\n";return 0;}
    cout << "YES\n";
    for(int i = 0; i < N-1; i++)cout << 2 <<" ";
    cout << S - 2*(N-1) << "\n" << 1;
    return 0;
}