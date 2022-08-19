#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long lint;
typedef pair<lint,int> pi;

int n,m;
lint d[200005], h[200005];
lint p[200005], q[200005];
struct seg{
    pi tree[530000];
    int lim;
    void init(int n, lint *a){
        fill(tree,tree+530000,pi(-1e18,0));
        for(lim = 1; lim <= n; lim <<= 1);
        for(int i=1; i<=n; i++){
            tree[lim + i] = pi(a[i],i);
        }
        for(int i=lim; i; i--){
            tree[i] = max(tree[2*i],tree[2*i+1]);
        }
    }
    pi q(int s, int e){
        pi ret(-1e18,0);
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) ret = max(ret,tree[s++]);
            if(e%2 == 0) ret = max(ret,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = max(ret,tree[s]);
        return ret;
    }
}rmqp, rmqq;

void input(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%I64d",&d[i]);
        if(i != n) d[i+n] = d[i];
    }
    for (int i=1; i<=n; i++) {
        scanf("%I64d",&h[i]);
        h[i+n] = h[i];
    }
    for (int i=1; i<=2*n-1; i++) {
        d[i] += d[i-1];
    }
    for (int i=1; i<=2*n; i++) {
        p[i] = 2ll * h[i] - d[i-1];
        q[i] = 2ll * h[i] + d[i-1];
    }
    rmqp.init(2*n,p);
    rmqq.init(2*n,q);
}

int main(){
    input();
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x <= y){
            swap(x,y);
            x++;
            y += n-1;
        }
        else{
            swap(x,y);
            x++;
            y--;
        }
        pi q1 = rmqp.q(x,y), q2 = rmqq.q(x,y);
        if(q1.second == q2.second){
            pi q1_rep, q2_rep;
            q1_rep = max(rmqp.q(x,q1.second-1),rmqp.q(q1.second+1,y));
            q2_rep = max(rmqq.q(x,q1.second-1),rmqq.q(q1.second+1,y));
            printf("%I64d\n",max(q1_rep.first + q2.first,q2_rep.first + q1.first));
        }
        else{
            printf("%I64d\n",q1.first + q2.first);
        }
    }
}