#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
long long a[200005];
vector<pair<long long,int>> vect;

int match[200005];

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
        vect.push_back(make_pair(a[i],i));
    }
    sort(vect.begin(),vect.end());
    for (int i=0; i<n; i++) {
        match[vect[i].second] = i;
        a[i] = vect[i].first;
    }
    while (m--) {
        int idx;
        long long b;
        scanf("%d %lld",&idx,&b);
        idx--;
        idx = match[idx];
        while (1) {
            int p = (int)(upper_bound(a,a+n,a[idx] + b) - a - 1);
            b -= (a[p] - a[idx]);
            int q = (int)(lower_bound(a,a+n,a[p] - b) - a);
            b -= (a[p] - a[q]);
            if(idx == p && p == q){
                printf("%d\n",vect[idx].second + 1);
                break;
            }
            idx = q;
            if(p != q) b %= 2ll * (a[p] - a[q]);
            idx = q;
        }
    }
}