#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
class FenwickTree {
private:
    vector<int> v;
    int n;
public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        if (x<1) return;
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int get(int x) const {
        int res=0;
        if (x>n) return (res);
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    int findPos(int x) const {
        int res=n+1;
        int mask=1;
        int tmp=0;
        while (mask<=n) mask<<=1; mask>>=1;
        while (mask>0) {
            if ((tmp|mask)<=n) {
                if (v[tmp|mask]>=x) res=min(res,tmp|mask);
                else {
                    tmp|=mask;
                    x-=v[tmp];
                }
            }
            mask>>=1;
        }
        return (res);
    }
};
int a[MAX],b[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n) a[i]++;
    FOR(i,1,n) b[i]++;
    if (n==1) {
        printf("0\n");
        exit(0);
    }
}
vector<int> add(const vector<int> &a,const vector<int> &b) {
    vector<int> res;
    int rem=0;
    REP(i,max(a.size(),b.size())) {
        int xa=i<a.size()?a[i]:0;
        int xb=i<b.size()?b[i]:0;
        res.push_back((xa+xb+rem)%(i+2));
        rem=(xa+xb+rem)/(i+2);
    }
    while (rem>0) {
        int tmp=res.size();
        res.push_back(rem%(tmp+2));
        rem/=tmp+2;
    }
    while (res.size()>1 && res.back()==0) res.pop_back();
    return (res);
}
vector<int> sub(const vector<int> &a,const vector<int> &b) {
    vector<int> res;
    int rem=0;
    REP(i,max(a.size(),b.size())) {
        int xa=i<a.size()?a[i]:0;
        int xb=i<b.size()?b[i]:0;
        if (xa<xb+rem) {
            res.push_back(xa-xb-rem+i+2);
            rem=1;
        } else {
            res.push_back(xa-xb-rem);
            rem=0;
        }
        //printf("At %d push %d\n",i,res.back());
    }
    while (res.size()>1 && res.back()==0) res.pop_back();
    return (res);
}
vector<int> permInfo(int a[]) {
    FenwickTree bit(n);
    FOR(i,1,n) bit.update(a[i],1);
    vector<int> res;
    FOR(i,1,n) {
        if (i<n) res.push_back(bit.get(a[i]-1));
        bit.update(a[i],-1);
    }
    reverse(res.begin(),res.end());
    while (res.size()>1 && res.back()==0) res.pop_back();
    return (res);
}
void process(void) {
    vector<int> resInfo=add(permInfo(a),permInfo(b));
    //vector<int> va=permInfo(a);
    //vector<int> vb=permInfo(b);
    //FORE(it,va) printf("%d ",*it); printf("\n");
    //FORE(it,vb) printf("%d ",*it); printf("\n");
    //FORE(it,resInfo) printf("%d ",*it); printf("\n");
    if (resInfo.size()>=n) {
        vector<int> tmp;
        FOR(i,1,n-1) tmp.push_back(i);
        resInfo=sub(resInfo,tmp);
        //FORE(it,resInfo) printf("%d ",*it); printf("\n");
        resInfo=sub(resInfo,vector<int>(1,1));
    }
    while (resInfo.size()<n-1) resInfo.push_back(0);
    reverse(resInfo.begin(),resInfo.end());
    //FORE(it,resInfo) printf("%d ",*it); printf("\n");
    resInfo.push_back(0);
    FenwickTree bit(n);
    FOR(i,1,n) bit.update(i,1);
    FOR(i,1,n) {
        int chs=bit.findPos(resInfo[i-1]+1);
        printf("%d ",chs-1);
        bit.update(chs,-1);
    }
    printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}