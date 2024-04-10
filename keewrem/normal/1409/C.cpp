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
ll N,x,y;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> x >> y;
        if(x > y)swap(x,y);
        ll delta;
        for(ll i = y-x; i > 0; i--){
            if((y-x)%i==0 && i*(N-1)>=y-x)delta = i;
        }
        ll st = max((x-1)%delta+1, y-(N-1)*delta);
        for(int i = 0; i < N; i++)cout << st+delta*i<<" \n"[i==N-1];
    }
    return 0;
}