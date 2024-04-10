#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

int n,s,c=0,x,y;

int main(){
    IOS;
    cin >> n >> s;
    vector<int> adj(n,0);
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        adj[x-1]++;
        adj[y-1]++;
    }
    for (int i = 0; i < n; i++){
        c += (adj[i] == 1);
    }
    cout << rnd(9) << (ld)s/c*2;
    return 0;
}