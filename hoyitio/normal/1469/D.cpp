#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
struct node{
    int id, x;
    bool operator < (const node& a) const{
        return x <a.x;
    }
};
priority_queue<node> q;
#define P pair<int,int>
vector<P> p;
int main()
{
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        while(q.size()) q.pop();
        p.clear();
        fors(i,1,n+1) q.push((node){i, i});
        while(1){
            node t1 = q.top(); q.pop();
            node t2 = q.top(); q.pop();
            if((ll)(t2.x-1) * (t2.x-1) > t1.x) {
                t2.x = 1;
                p.pb(P(t2.id, t1.id));
                q.push(t2); q.push(t1);
            }else {
                if(t2.x == 1) break;
                t1.x = (t1.x + t2.x - 1)/t2.x;
                p.pb(P(t1.id, t2.id));
                q.push(t2); q.push(t1);
            }
        }
        printf("%d\n", p.size());
        fors(i,0,p.size()) printf("%d %d\n", p[i].first, p[i].second);
    }
}