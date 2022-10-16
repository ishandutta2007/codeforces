#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
class BIT {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        if (x<1 || x>n) return (0);
        //printf("GET %d\n",x);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        //printf("OK\n");
        return (ret);
    }
    void add(int x,int d) {
        if (x<1 || x>n) return;
        //printf("ADD %d\n",x);
        for (;x<=n;x+=x&(-x)) v[x]+=d;
        //printf("OK\n");
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    int count(int x) {
        return (get(n)-get(x-1));
    }
    void update(int x,int d) {
        add(x,d);
    }
};
vector<int> v[MAX];
map<ii,int> mp;
BIT bit;
int n,p;
int nag[MAX];
void init(void) {
    scanf("%d%d",&n,&p);
    FOR(i,1,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);
        if (mp.find(ii(x,y))==mp.end()) {
            v[x].push_back(y);
            v[y].push_back(x);
        }
        mp[ii(x,y)]++;
        nag[x]++;
        nag[y]++;
    }
    bit=BIT(n);
}
inline int getmap(int x,int y) {
    if (x>y) return (getmap(y,x));
    map<ii,int>::iterator it=mp.find(ii(x,y));
    if (it==mp.end()) return (0);
    return (it->se);
}
int count(int x) {
    if (nag[x]>=p) return (n-1);
    //printf("COUNT %d\n",x);
    FORE(it,v[x]) {
        bit.update(nag[*it],-1);
        bit.update(nag[*it]-getmap(x,*it),1);
    }
    //printf("XXX\n");
    int ret=bit.count(p-nag[x]);
    //printf("XXX\n");
    FORE(it,v[x]) {
        bit.update(nag[*it],1);
        bit.update(nag[*it]-getmap(x,*it),-1);
    }
    if (nag[x]>=p-nag[x]) ret--;
    //printf("END %d\n",ret);
    return (ret);
}
void process(void) {
    FOR(i,1,n) bit.update(nag[i],1);
    ll res=0;
    FOR(i,1,n) res+=count(i);
    //printf("%d\n",n);
    assert(res%2==0);
    cout<<res/2;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}