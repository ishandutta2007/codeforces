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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        vi c[N+1];
        for(int i = 0; i < N+1; i++)c[i].pb(0);
        for(int i = 0; i < N; i++)c[v[i]].pb(i+1);
        for(int i = 0; i < N+1; i++)c[i].pb(N+1);
        vector<pii> kek(N+1);
        for(int i = 0; i <= N; i++)kek[i]={0,i};
        for(int i = 0; i < N+1; i++){
            for(int j = 0; j < c[i].size()-1; j++)kek[i].fi = max(kek[i].fi,c[i][j+1]-c[i][j]);
        }
        sort(kek.begin(),kek.end());
        int ind = -1;
        priority_queue<int> pq;
        for(int i = 1; i<=N; i++){
            while(ind < N && kek[ind+1].fi<=i){ind++; pq.push(-kek[ind].se);}
            if(pq.empty())cout << "-1 ";
            else cout << -pq.top()<<" ";
        }
        cout << "\n";

    }
    return 0;
}