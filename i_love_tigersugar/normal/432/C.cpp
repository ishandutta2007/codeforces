#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
bool notprime[MAX];
vector<int> prime;
vector<ii> res;
int gold[MAX];
int a[MAX],p[MAX];
int n;
void eratosthene(void) {
    REP(i,2) notprime[i]=true;
    FOR(i,2,MAX-1) if (!notprime[i]) {
        prime.push_back(i);
        for (int j=2*i;j<MAX;j=j+i) notprime[j]=true;
    }
}
void goldbach(void) {
    FOR(i,4,MAX-1) if (i%2==0) {
        bool ok=false;
        FORE(it,prime) {
            assert(!notprime[*it]);
            if (*it>i-*it) break;
            if (!notprime[i-*it]) {
                gold[i]=*it;
                ok=true;
                break;
            }
        }
        assert(ok);
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }

}
void oper(int i,int j) {
    res.push_back(ii(i,j));
    swap(a[i],a[j]);
    p[a[i]]=i;
    p[a[j]]=j;
}
void move(int p,int k) {
    if (k<=5) {
        REP(i,k) oper(p-i-1,p-i);
        return;
    }
    if (k&1) {
        oper(p-1,p);
        p--;
        k--;
    }
    int x=gold[k+2];
    oper(p-x+1,p);
    p-=x-1;
    oper(p-(k+2-x)+1,p);
}
void process(void) {
    FOR(i,1,n) move(p[i],p[i]-i);
    printf("%d\n",res.size());
    FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    eratosthene();
    goldbach();
    init();
    process();
    return 0;
}