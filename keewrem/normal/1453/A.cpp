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
ll N,M;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        set<int> a; int b;
        for(int i = 0; i < N; i++){
            cin >> b; a.insert(b);
        }
        for(int i = 0; i < M; i++){
            cin >> b; a.insert(b);
        }
        cout << M + N - (int)a.size()<<"\n";
    }
    return 0;
}