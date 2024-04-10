#include<cstdio>
#include<set>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
bool notprime[MAX];
vector<int> div[MAX];
set<int> s[MAX];
int n,q;
bool stt[MAX];
void eratosthene(void) {
    scanf("%d",&n);
    REP(i,2) notprime[i]=true;
    FOR(i,2,n) if (!notprime[i]) {
        div[i].push_back(i);
        for (int j=2*i;j<=n;j=j+i) {
            notprime[j]=true;
            div[j].push_back(i);
        }
    }
}
void active(int x) {
    if (stt[x]) {
        printf("Already on\n");
        return;
    }
    FORE(it,div[x]) if (!s[*it].empty()) {
        printf("Conflict with %d\n",*s[*it].begin());
        return;
    }
    stt[x]=true;
    FORE(it,div[x]) s[*it].insert(x);
    printf("Success\n");
}
void deactive(int x) {
    if (!stt[x]) {
        printf("Already off\n");
        return;
    }
    stt[x]=false;
    FORE(it,div[x]) s[*it].erase(x);
    printf("Success\n");
}
void process(void) {
    scanf("%d",&q);
    REP(zz,q) {
        char c;
        int x;
        scanf(" %c %d",&c,&x);
        if (c=='+') active(x);
        else deactive(x);
    }
}
int main(void) {
    eratosthene();
    process();
    return 0;
}