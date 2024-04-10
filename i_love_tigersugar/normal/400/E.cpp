#include<bits/stdc++.h>
#define MAX   100100
#define nbit   19
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define bit(x,i) ((x)&(1<<(i)))
#define SUM(x) (1LL*(x)*((x)+1)/2)
using namespace std;
typedef long long ll;
typedef set<int>::iterator sit;
set<int> s[nbit];
int a[MAX];
ll res;
int n,q;
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        REP(j,nbit) if (!bit(a[i],j)) s[j].insert(i);
    }
    REP(j,nbit) {
        s[j].insert(0);
        s[j].insert(n+1);
    }
    int prev=-1;
    REP(i,nbit) {
        ll sum=0;
        FORE(it,s[i]) {
            if (it!=s[i].begin()) sum+=SUM(*it-prev-1);
            prev=*it;
        }
        res+=sum*(1LL<<i);
    }
}
ll change(int p,int x,int v) {
    if (bit(a[x],p)==bit(v,p)) return (0);
    if (bit(v,p)) {
        sit it=s[p].find(x);
        assert(it!=s[p].end());
        it--;
        int l=*it;
        it++;it++;
        int r=*it;
        s[p].erase(x);
        return (SUM(r-l-1)-SUM(r-x-1)-SUM(x-l-1));
    }
    else {
        assert(s[p].find(x)==s[p].end());
        sit it=s[p].insert(x).first;
        it--;
        int l=*it;
        it++;it++;
        int r=*it;
        return (SUM(r-x-1)+SUM(x-l-1)-SUM(r-l-1));
    }
}
void process(void) {
    REP(i,q) {
        int p,x;
        scanf("%d%d",&p,&x);
        REP(j,nbit) res+=change(j,p,x)*(1LL<<j);
        a[p]=x;
        cout << res << "\n";
    }
}
int main(void) {
    init();
    process();
    return 0;
}