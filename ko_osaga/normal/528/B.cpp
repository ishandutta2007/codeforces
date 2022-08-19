#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

struct rmq{
    int tree[1050000], lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = max(tree[x],v);
        while(x > 1){
            x >>= 1;
            tree[x] = max(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        s += lim;
        e += lim;
        int ret = 0;
        while(s < e){
            if(s%2 == 1) ret = max(ret,tree[s++]);
            if(e%2 == 0) ret = max(ret,tree[e--]);
            s /=2;
            e /=2;
        }
        if(s == e) ret = max(ret,tree[s]);
        return ret;
    }
}rmq;

int n, dp[200005];
pi a[200005];
vector<int> v;

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
        v.push_back(a[i].first + a[i].second);
        v.push_back(a[i].first - a[i].second);
    }
    v.push_back(-2e9);
    sort(v.begin(),v.end());
    sort(a,a+n);
    rmq.init(2*n);
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for (int i=n-1; i>=0; i--) {
        int piv1 = (int)(lower_bound(v.begin(),v.end(),a[i].first + a[i].second) - v.begin());
        int piv2 = (int)(lower_bound(v.begin(),v.end(),a[i].first - a[i].second) - v.begin());
        dp[i] = rmq.q(piv1,2*n)+1;
        rmq.add(piv2,dp[i]);
    }
    printf("%d",*max_element(dp,dp+n));
}