#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int n,k;
int rem[MAX];
bool ok[MAX][MAX];
vector<ii> v;
bool cmp(const int &a,const int &b) {
    return (rem[a]>rem[b]);
}
void process(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) rem[i]=n-1;
    FOR(i,1,n) FOR(j,1,n) ok[i][j]=(i!=j);
    FOR(i,1,n) {
        int cnt=0;
        FOR(j,1,i-1) if (ok[i][j] && cnt<k) {
            cnt++;
            v.push_back(ii(i,j));
            ok[j][i]=false;
            rem[j]--;
        }
        vector<int> touse;
        FOR(j,i+1,n) if (ok[i][j]) touse.push_back(j);
        if (touse.size()<k-cnt) {
            printf("-1");
            return;
        }
        sort(touse.begin(),touse.end(),cmp);
        REP(j,k-cnt) {
            v.push_back(ii(i,touse[j]));
            ok[touse[j]][i]=false;
            rem[touse[j]]--;
        }
    }
    printf("%d\n",v.size());
    FORE(it,v) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    process();
    return 0;
}