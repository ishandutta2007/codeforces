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
        vi v(N), b(N);
        for(int i = 0; i < N; i++)cin >>v[i];
        for(int i = 0; i < N; i++)cin >>b[i];
        bool k =0;
        for(int i = 1; i < N; i++)if(b[i]!=b[i-1])k = 1;
        if(k){
            cout << "Yes\n"; continue;
        }else{
            for(int i = 1; i < N; i++){
                if(v[i]<v[i-1]){
                    k = 1; break;
                }
            }
        }
        if(k)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}