#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

struct rmq{
    int tree[270000],lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
        fill(tree,tree+2*lim,1e9);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = min(tree[x],v);
        while(x > 1){
            x >>= 1;
            tree[x] = min(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        s += lim;
        e += lim;
        int ret = 1e9;
        while(s < e){
            if(s%2 == 1) ret = min(ret,tree[s++]);
            if(e%2 == 0) ret = min(ret,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = min(ret,tree[s]);
        return ret;
    }
}rmq1,rmq2;

vector<int> v;
int a[100005], n;
int lowpoint[100005], highpoint[100005];

void solve(){
    scanf("%d",&n);
    v.clear();
    v.push_back(-1e9);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i=0; i<n; i++) {
        a[i] = (int)(lower_bound(v.begin(),v.end(),a[i]) - v.begin());
    }
    rmq1.init((int)v.size());
    rmq2.init((int)v.size());
    for (int i=n-1; i>=0; i--) {
        lowpoint[i] = rmq1.q(0,a[i]-1);
        highpoint[i] = rmq2.q(a[i]+1,(int)v.size());
        rmq1.add(a[i],i);
        rmq2.add(a[i],i);
    }
    for (int i=1; i<n; i++) {
        if(a[0] < a[i]){
            if(lowpoint[i] > n) continue;
            printf("3\n%d %d %d\n",1,i+1,lowpoint[i]+1);
            return;
        }
        if(a[0] > a[i]){
            if(highpoint[i] > n) continue;
            printf("3\n%d %d %d\n",1,i+1,highpoint[i]+1);
            return;
        }
    }
    puts("0");
}

int main(){
        solve();

}