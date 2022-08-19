#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int pp[500005];
int cnt[500005];
int n,q;
int a[200005];
bool sw[200005];

int main(){
    scanf("%d %d",&n,&q);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=2; i<=500000; i++) {
        for (int j=i; j<=500000; j+=i) {
            if(!pp[j]) pp[j] = i;
        }
    }
    long long ret = 0;
    while (q--) {
        int t;
        scanf("%d",&t);
        vector<int> v;
        int u = a[t];
        while (u != 1) {
            v.push_back(pp[u]);
            u /= pp[u];
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end()) - v.begin());
        int res = 0;
        for (int i=0; i<(1<<v.size()); i++) {
            int num = 1, bits = 0;
            for (int j=0; j<v.size(); j++) {
                if((i>>j) & 1) num *= v[j], bits++;
            }
            if(bits % 2 == 1){
                res -= cnt[num];
            }
            else{
                res += cnt[num];
            }
        }
        if(sw[t]){
            ret -= res - 1 + (a[t] != 1);
        }
        else{
            ret += res;
        }
        printf("%lld\n",ret);
        for (int i=0; i<(1<<v.size()); i++) {
            int num = 1;
            for (int j=0; j<v.size(); j++) {
                if((i>>j) & 1) num *= v[j];
            }
            if(!sw[t]){
                cnt[num]++;
            }
            else{
                cnt[num]--;
            }
        }
        sw[t] ^= 1;
    }
}