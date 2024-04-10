#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define fi   first
#define se   second
using namespace std;
pair<int,int> a[MAX];
int n,k;
int main(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) {
        scanf("%d",&a[i].fi);
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    vector<int> res;
    FOR(i,1,n) if (a[i].fi<=k) {
        res.push_back(a[i].se);
        k-=a[i].fi;
    }
    printf("%d\n",(int)res.size());
    FOR(i,0,(int)res.size()-1) printf("%d ",res[i]);
    printf("\n");
    return 0;
}