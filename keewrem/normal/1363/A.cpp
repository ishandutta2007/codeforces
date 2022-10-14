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
ll N,X,a,b;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> X;
        cin >> a; ll s = a;
        bool q = 1; ll k = N;
        while(--k){
            cin>>b; s += b;
            if((abs(b-a))&1)q = 0;
        }
        if(q && a%2 == 0){cout<< "No\n"; continue;}
        if(q && X%2==0){cout<< "No\n"; continue;}
        if(s%2LL == 0 && X == N){cout<< "No\n"; continue;}
        cout << "Yes\n";
    }
    return 0;
}