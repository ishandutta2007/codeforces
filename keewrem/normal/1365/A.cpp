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
int N,M;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        int a = N, b = M;
        int sas[N][M];
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++)cin >> sas[i][j];
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            if(sas[i][j]){
                a--; break;
            }
        }
        for(int i = 0; i < M; i++)for(int j = 0; j < N; j++){
            if(sas[j][i]){
                b--; break;
            }
        }
        int c =  min(a,b);
        if(c&1)cout << "Ashish";
        else cout << "Vivek";
        cout << "\n";
    }
    return 0;
}