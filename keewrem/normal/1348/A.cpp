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
        int a = 0, b = 0;
        for(int i  = 1; i <= N; i++){
            if(i < N/2 || i == N)a+=(1<<i);
            else b+= (1<<i);
        }
        cout << abs(b-a)<<"\n";
    }
    return 0;
}