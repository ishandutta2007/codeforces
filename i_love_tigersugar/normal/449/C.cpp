#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
bool notprime[MAX],match[MAX];
int n;
vector<ii> res;
void process(void) {
    scanf("%d",&n);
    FOR(i,2,n) if (!notprime[i])
        for (int j=2*i;j<=n;j=j+i) notprime[j]=true;
    FORD(i,n/2,2) if (!notprime[i]) {
        vector<int> rem;
        for (int j=i;j<=n;j=j+i) if (!match[j]) rem.push_back(j);
        if (rem.size()%2) rem.erase(rem.begin()+1);
        FORE(it,rem) match[*it]=true;
        while (!rem.empty()) {
            int u=rem.back();rem.pop_back();
            int v=rem.back();rem.pop_back();
            res.push_back(ii(u,v));
        }
    }
    printf("%d\n",res.size());
    FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    process();
    return 0;
}