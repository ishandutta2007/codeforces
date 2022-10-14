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

int T = 1;
ll N,K;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vi x(N), y(N);
        for(int i = 0; i < N; i++)cin >> x[i]>>y[i];
        bool r = 0;
        for(int i = 0; i < N; i++){
            bool k = 1;
            for(int j = 0; j < N; j++){
                if(abs(x[i]-x[j])+abs(y[i]-y[j])>K)k = 0;
            }
            if(k)r = 1;
        }
        if(r)cout <<"1\n";
        else cout << "-1\n";
    }
    return 0;
}