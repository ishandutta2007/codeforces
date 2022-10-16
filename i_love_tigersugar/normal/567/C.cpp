#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,k,a[MAX];
map<int,long long> mp[3];
long long cnt[3][MAX];
void init(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    long long res=0;
    FOR(i,1,n) {
        cnt[0][i]=a[i]%k==0?mp[0][a[i]/k]:0;
        cnt[1][i]=a[i]%k==0?mp[1][a[i]/k]:0;
        res+=cnt[1][i];
        mp[0][a[i]]++;
        mp[1][a[i]]+=cnt[0][i];
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}