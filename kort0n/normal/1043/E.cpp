#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
    ll deltasum[300050];
    vector<int> disconnected[300050];
    ll ans[300050];
    ll x[300050];
    ll y[300050];

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    ll xsum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &x[i], &y[i]);
        //cin >> x[i] >> y[i];
        xsum += x[i];
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        //cin >> u >> v;
        scanf("%d%d", &u, &v);
        disconnected[u].push_back(v);
        disconnected[v].push_back(u);
    }
    vector<ll> delta(n);
    for(int i = 0; i < n; i++){
        delta[i] = y[i + 1] - x[i + 1];
    }
    sort(delta.begin(), delta.end());
    deltasum[0] = 0;
    for(int i = 1; i <= n; i++){
        //cout << "deltai-1 " << delta[i - 1] << endl;
        deltasum[i] = deltasum[i - 1] + delta[i - 1];
        //cout << i << " " << deltasum[i] << endl;
    }
    //cout << xsum << endl;
    for(int i = 1; i <= n; i++){
        ll Idelta = y[i] - x[i];
        ans[i] = xsum + (n - 2) * x[i] - Idelta;
        int index = distance(delta.begin(), lower_bound(delta.begin(), delta.end(), Idelta)); 
        //cout << "index" << i << " " << index << endl;
        ans[i] += deltasum[index] + Idelta * (n - index);
        //cout << i << " " << ans[i] << endl;
    }
    //cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < disconnected[i].size(); j++){
            int newi = disconnected[i][j];
            ans[i] -= min(x[i] + y[newi], x[newi] + y[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        //cout << ans[i];
        printf("%lld", ans[i]);
        if(i < n){
            //cout << " ";
            printf(" ");
        }
    }
    //cout << endl;
    printf("\n");
    return 0;
}