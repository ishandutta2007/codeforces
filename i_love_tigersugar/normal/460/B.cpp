#include<cstdio>
#include<set>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e9;
set<int> res;
int a,b,c;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int sdis(ll x) {
    int res=0;
    while (x>0) {
        res+=x%10;
        x/=10;
    }
    return (res);
}
ll pw(int a,int b) {
    int res=1;
    REP(zz,b) res*=a;
    return (res);
}
void process(void) {
    a=nextInt();
    b=nextInt();
    c=nextInt();
    FOR(i,1,81) {
        ll x=pw(i,a)*b+c;
        if (x>0 && x<INF && sdis(x)==i) res.insert(x);
    }
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d ",*it);
}
int main(void) {
    process();
    return 0;
}