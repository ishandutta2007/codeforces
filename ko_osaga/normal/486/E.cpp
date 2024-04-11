#include <cstdio>
#include <algorithm>
using namespace std;

struct rmq{
    int tree[270000], lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = v;
        while(x > 1){
            x >>= 1;
            tree[x] = max(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        s += lim;
        e += lim;
        int res = 0;
        while(s < e){
            if(s%2 == 1) res = max(res,tree[s++]);
            if(e%2 == 0) res = max(res,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) res = max(res,tree[s]);
        return res;
    }
}rmq,rmq2;

int n,a[100005];
int lis_end[100005], lis_start[100005];

int cnt[100005];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    rmq.init(100000);
    rmq2.init(100000);
    for (int i=n-1; i>=0; i--) {
        lis_end[i] = rmq.q(a[i]+1,100000) + 1;
        rmq.add(a[i],lis_end[i]);
    }
    for (int i=0; i<n; i++) {
        lis_start[i] = rmq2.q(0,a[i]-1) + 1;
        rmq2.add(a[i],lis_start[i]);
    }
    int len = *max_element(lis_end,lis_end+n);
    for (int i=0; i<n; i++) {
        if(lis_end[i] + lis_start[i] == len + 1) cnt[lis_start[i]]++;
    }
    for (int i=0; i<n; i++) {
        if(lis_end[i] + lis_start[i] != len + 1){
            printf("1");
        }
        else if(cnt[lis_start[i]] == 1){
            printf("3");
        }
        else printf("2");
    }
}