#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
class DisjointSet {
    private:
    vector<int> lab;
    int find(int x) {
        return (lab[x]<0?x:lab[x]=find(lab[x]));
    }
    public:
    DisjointSet(){}
    DisjointSet(int n) {
        lab.assign(n+7,-1);
    }
    bool join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return (false);
        if (lab[x]>lab[y]) swap(x,y);
        lab[x]+=lab[y];
        lab[y]=x;
        return (true);
    }
    bool sameSet(int x,int y) {
        return (find(x)==find(y));
    }
};
int n,m;
void process(void) {
    scanf("%d%d",&n,&m);
    DisjointSet dsu(2*n);
    int cntComp=2*n;
    REP(love,m) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (c==0) {
            if (dsu.join(a,n+b)) cntComp--;
            if (dsu.join(b,n+a)) cntComp--;
        } else {
            if (dsu.join(a,b)) cntComp--;
            if (dsu.join(a+n,b+n)) cntComp--;
        }
    }
    FOR(i,1,n) if (dsu.sameSet(i,i+n)) {
        printf("0\n");
        return;
    }
    int res=1;
    REP(love,cntComp/2-1) res=res*2%mod;
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}