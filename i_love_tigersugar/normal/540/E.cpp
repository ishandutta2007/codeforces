#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FORED(i,v) for (__typeof((v).rbegin()) i=(v).rbegin();i!=(v).rend();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
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
        for (;x<=n;x+=x&-x) v[x]++;
    }
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
};
vector<int> seq,pos;
vector<pair<int,int> > sw;
void init(void) {
    int n;
    scanf("%d",&n);
    REP(love,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        pos.push_back(x);
        pos.push_back(y);
        sw.push_back(make_pair(x,y));
    }
    sort(ALL(pos));
    pos.resize(unique(ALL(pos))-pos.begin());
    seq=pos;
    FORE(it,sw) {
        int idX=lower_bound(ALL(pos),it->fi)-pos.begin();
        int idY=lower_bound(ALL(pos),it->se)-pos.begin();
        swap(seq[idX],seq[idY]);
    }
}
long long inversion(vector<int> v) {
    vector<int> val;
    FORE(it,v) val.push_back(*it);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FenwickTree bit(val.size());
    long long res=0;
    FORED(it,v) {
        int x=lower_bound(ALL(val),*it)-val.begin()+1;
        if (x>1) res+=bit.get(x-1);
        bit.update(x);
    }
    return (res);
}
int countRange(int l,int r) {
    int L=lower_bound(ALL(pos),l)-pos.begin();
    int R=upper_bound(ALL(pos),r)-pos.begin();
    return (max(R-L,0));
}
void process(void) {
    long long res=inversion(seq);
    REP(j,seq.size()) {
        int x=seq[j];
        int i=pos[j];
        //printf("s %d = %d\n",i,x);
        if (i+1<=x-1) res+=x-i-1-countRange(i+1,x-1);
        if (x+1<=i-1) res+=i-x-1-countRange(x+1,i-1);
        //printf("after %d is %d\n",i,res);
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}