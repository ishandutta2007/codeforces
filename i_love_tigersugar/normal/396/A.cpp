#include<bits/stdc++.h>
#define MAXV   100100
#define MAXN   506
#define MAXM   15551
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int mod=(int)1e9+7;
int f[MAXN][MAXM],s[MAXN][MAXM];
bool notprime[MAXV];
vector<int> prime;
map<int,int> mp;
int a[MAXN];
int n;
void eratosthene(void) {
    REP(i,2) notprime[i]=true;
    FOR(i,2,MAXV-1) if (!notprime[i]) {
        prime.push_back(i);
        for (int j=2*i;j<MAXV;j=j+i) notprime[j]=true;
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void anal(int x) {
    FORE(it,prime) {
        if (1LL*(*it)*(*it)>x) break;
        int tmp=0;
        while (x%*it==0) {
            tmp++;
            x=x/(*it);
        }
        mp[*it]+=tmp;
    }
    if (x>1) mp[x]++;
}
void optimize(void) {
    f[0][0]=1;
    FOR(j,0,MAXM-1) s[0][j]=1;
    FOR(i,1,n) FOR(j,0,MAXM-1) {
        f[i][j]=s[i-1][j];
        if (j>0) s[i][j]=(s[i][j-1]+f[i][j])%mod; else s[i][j]=f[i][j];
    }
}
void process(void) {
    FOR(i,1,n) anal(a[i]);
    int res=1;
    FORE(it,mp) {
        //printf("%d %d\n",it->fi,it->se);
        int x=it->se;
        res=1LL*res*f[n][x]%mod;
    }
    printf("%d",res);
}
int main(void) {
    eratosthene();
    init();
    optimize();
    process();
    return 0;
}