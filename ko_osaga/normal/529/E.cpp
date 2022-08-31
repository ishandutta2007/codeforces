#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pi;

vector<pi> money[21]; // i can use less than K money

int n,k,a[5005];

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        for (int j=0; j<=k; j++) {
            for (int l=j; l<=k; l++) {
                money[l].push_back(pi(a[i]*j,j));
            }
        }
    }
    for (int i=0; i<=k; i++) {
        sort(money[i].begin(),money[i].end());
        money[i].resize(unique(money[i].begin(),money[i].end()) - money[i].begin());
    }
    int q;
    scanf("%d",&q);
    while (q--) {
        int t;
        scanf("%d",&t);
        int ret = 1e9;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=k && a[i] * j <= t; j++) {
                int p = t - a[i] * j;
                auto it = lower_bound(money[k-j].begin(),money[k-j].end(),pi(p,0));
                if(it != money[k-j].end() && it->first == p){
                    ret = min(ret,j + (it->second));
                }
            }
        }
        if(ret > 1e8) puts("-1");
        else printf("%d\n",ret);
    }
}