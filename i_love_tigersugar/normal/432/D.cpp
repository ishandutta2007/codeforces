#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
char s[MAX];
int z[MAX],v[MAX];
int n;
void init(void) {
    scanf("%s",s);
    n=strlen(s);
}
void zalgor(void) {
    int L=0;
    int R=0;
	FOR(i,1,n-1) {
        if (i>R) {
            L=R=i;
            while (R<n && s[R-L]==s[R]) R++;
            z[i]=R-L;
            R--;
        }
        else {
            int k=i-L;
            if (z[k]<R-i+1) z[i]=z[k];
            else {
                L=i;
                while (R<n && s[R-L]==s[R]) R++;
                z[i]=R-L;
                R--;
            }
        }
    }
    z[0]=n;
    REP(i,n) v[i]=z[i];
    sort(v,v+n,greater<int>());
    //REP(i,n) printf("%d ",z[i]); printf("\n");
}
void process(void) {
    vector<ii> res;
    FOR(i,1,n) if (z[n-i]==i) res.push_back(ii(i,upper_bound(v,v+n,i,greater<int>())-v));
    printf("%d\n",res.size());
    FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    init();
    zalgor();
    process();
    return 0;
}