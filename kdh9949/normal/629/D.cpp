#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

double PI = 3.141592653589793238;

struct SegTree{
    ll data[262145];
    int sz;
    SegTree(int n){
        for(sz = 1; sz < n; sz *= 2);
        for(int i = 1; i < sz + n; i++) data[i] = 0;
    }
    void update(int x, ll val){
        x += sz - 1;
        data[x] = max(data[x], val);
        while(x > 1){
            x /= 2;
            data[x] = max(data[2 * x], data[2 * x + 1]);
        }
    }
    ll segmax(int s, int e){
        ll ret = 0;
        s += sz - 1; e += sz - 1;
        while(s <= e){
            if(s % 2) ret = max(ret, data[s++]);
            if(e % 2 == 0) ret = max(ret, data[e--]);
            s /= 2; e /= 2;
        }
        return ret;
    }
};

struct Cake{
    int r, h;
    ll volume() const {
        return (ll)r * r * h;
    }
    bool operator<(const Cake &a) const {
        return this -> volume() < a.volume();
    }
};

int n;
Cake a[100010], sa[100010];
SegTree *ST;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &a[i].r, &a[i].h);
        sa[i] = a[i];
    }
    sort(sa + 1, sa + n + 1);
    ST = new SegTree(n);
    for(int i = 1; i <= n; i++){
        int t = (int)(lower_bound(sa + 1, sa + n + 1, a[i]) - sa);
        ST -> update(t, ST -> segmax(1, t - 1) + a[i].volume());
    }
    printf("%.10lf", PI * ST -> segmax(1, n));
}