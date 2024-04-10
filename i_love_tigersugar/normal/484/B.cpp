#include<bits/stdc++.h>
#define MAXN   200200
#define MAXV   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
using namespace std;
class FenwickTree {
    private:
    int n;
    vector<int> v;
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]++;
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    int findPos(int x) const {
        int res=n+1;
        int cur=0;
        FORD(i,21,0) if ((cur|MASK(i))<=n) {
            if (v[cur|MASK(i)]>=x) res=min(res,cur|MASK(i));
            else {
                cur|=MASK(i);
                x-=v[cur];
            }
        }
        return (res);
    }
};
vector<int> a;
void init(void) {
    int n;
    scanf("%d",&n);
    FOR(i,1,n) {
        int t;
        scanf("%d",&t);
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());
}
void process(void) {
    int res=0;
    FenwickTree fenwickTree(MAXV);
    FORD(i,(int)a.size()-1,0) {
        if (a[i]-1<=res) break;
        fenwickTree.update(a[i]);
        for (int j=a[i];j<=MAXV;j=j+a[i]) {
            int tmp=fenwickTree.get(min(MAXV,j+a[i]-1));
            int pos=fenwickTree.findPos(tmp);
            if (pos>=j) res=max(res,pos-j);
        }
    }
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}