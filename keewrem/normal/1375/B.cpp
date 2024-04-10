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
ll N,M;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        int g[N][M];
        bool k = 0; int a;
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            g[i][j]=4-(i==0 || i == N-1)-(j==0 || j == M-1);
            cin >> a;
            if(a > g[i][j])k=1;
        }
        if(k){cout << "NO\n"; continue;}
        cout << "YES\n";
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            cout << g[i][j]<<" \n"[j==M-1];
        }
    }
    return 0;
}