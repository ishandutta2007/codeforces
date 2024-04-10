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
ll N,M,a;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            cin >> a;
            if(a % 2 == (i+j)%2)cout << a;
            else cout << a+1;
            cout << " \n"[i==N-1];
        }
    }
    return 0;
}