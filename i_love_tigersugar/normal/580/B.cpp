#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define left    ___left
#define right    ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
pair<int,int> a[MAX];
int n,d;
void process(void) {
    scanf("%d%d",&n,&d);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1);
    int j=1;
    long long sum=a[1].se;
    long long res=a[1].se;
    FOR(i,1,n) {
        while (j<n && a[j+1].fi-a[i].fi<d) {
            j++;
            sum+=a[j].se;
        }
        maximize(res,sum);
        sum-=a[i].se;
    }
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}