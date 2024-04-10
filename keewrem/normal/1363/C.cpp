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
ll N,X,a;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> X;
        ll c = 0;
        for(int i = 0; i < 2*N-2; i++){cin >> a; if(a == X)c++;}
        if(c < 2 || N%2==0){cout << "Ayush\n"; continue;}
        cout << "Ashish\n";
    }
    return 0;
}