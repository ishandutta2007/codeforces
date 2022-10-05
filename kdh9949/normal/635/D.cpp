#include <cstdio>
#include <algorithm>
using namespace std;

struct SegTree{
    int lim, sz;
    int data[524289];
    SegTree(int n, int l) : lim(l) {
        for(sz = 1; sz < n; sz *= 2);
        for(int i = 1; i < 2 * sz; i++) data[i] = 0;
    }
    void update(int x, int val){
        x += sz - 1;
        data[x] += val;
        data[x] = min(data[x], lim);
        x /= 2;
        while(x){
            data[x] = data[2 * x] + data[2 * x + 1];
            x /= 2;
        }
    }
    int segsum(int s, int e){
        s += sz - 1; e += sz - 1;
        int ret = 0;
        while(s <= e){
            if(s % 2 == 1) ret += data[s++];
            if(e % 2 == 0) ret += data[e--];
            s /= 2; e /= 2;
        }
        return ret;
    }
};

SegTree *PT, *ST;
int n, k, a, b, q;
int order, d, v;

int main(){
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    PT = new SegTree(n, b);
    ST = new SegTree(n, a);
    for(int i = 0; i < q; i++){
        scanf("%d", &order);
        if(order == 1){
            scanf("%d%d", &d, &v);
            PT -> update(d, v);
            ST -> update(d, v);
        }
        else{
            scanf("%d", &d);
            printf("%d\n", PT -> segsum(1, d - 1) + ST -> segsum(d + k, n));
        }
    }
}