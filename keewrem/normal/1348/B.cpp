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
        vi v(N);
        set<int> s;
        for(int i = 0; i< N; i++){
            cin >> v[i]; s.insert(v[i]);
        }
        if(M < s.size()){
            cout << "-1\n";continue;}

        int q = 1;
        while(s.size()<M){
            s.insert(q++);
        }
            cout << N*s.size()<<"\n";
            for(int i = 0 ; i < N; i++){
                for(auto x: s)cout << x << " ";
            }
            cout << "\n";

    }
    return 0;
}