#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;

int n, u, k;
vector<int> v[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> u;
        int cont = 0;
        while( u > 0 ){
            v[u].push_back(cont);
            u /= 2;
            cont++;
        }
    }

    int ans = inf, curr;
    for(int i=1; i<=200000; i++){
        if( v[i].size() >= k ){
            curr = 0;
            sort(v[i].begin(),v[i].end());
            for(int j=0; j<k; j++)
                curr += v[i][j];
        }
        ans = min( ans , curr );
    }

    cout << ans << '\n';

    return 0;
}