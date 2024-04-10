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
ll N ,M;
int a,b;
vi adj[500010];
vi q;
vector<pair<int,int>> v;
void blocc(){
    cout << -1;
    exit(0);
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    q.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> q[i]; v.pb({q[i],i});
    }
    bool kek[N+1]; int c;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= q[i]; j++){
            kek[j] =0;
        }
        c = 0;
        for(auto x: adj[i]){
            if(q[x]== q[i])blocc();
            if(q[x]>q[i])continue;
            if(kek[q[x]]==0)c++;
            kek[q[x]] = 1;
        }
        if(c < q[i]-1)blocc();


    }
    sort(v.begin(),v.end());
    for(auto x: v){
        cout<< x.se << " ";
    }
    return 0;
}