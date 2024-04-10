#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int n, x[200010], y[200010];
map<int, int> ver, hor;
map<pair<int, int>, int> samexy;
ll ans;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
    for(int i = 0; i < n; i++){
        ver[x[i]]++;
        hor[y[i]]++;
        samexy[make_pair(x[i], y[i])]++;
    }
    for(map<int, int>::iterator it = ver.begin(); it != ver.end(); it++){
        ans += (ll)(it -> second) * (it -> second - 1) / 2ll;
    }
    for(map<int, int>::iterator it = hor.begin(); it != hor.end(); it++){
        ans += (ll)(it -> second) * (it -> second - 1) / 2ll;
    }
    for(map<pair<int, int>, int>::iterator it = samexy.begin(); it != samexy.end(); it++){
        ans -= (ll)(it -> second) * (it -> second - 1) / 2ll;
    }
    printf("%I64d", ans);
}