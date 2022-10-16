#include<bits/stdc++.h>
#define MAX   2228
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
char a[MAX];
vector<int> v;
int m,n;
void process(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) {
        scanf("%s",a+1);
        int idg,ids;
        FOR(j,1,n) {
            if (a[j]=='G') idg=j;
            if (a[j]=='S') ids=j;
        }
        if (ids<idg) {
            printf("-1");
            return;
        }
        v.push_back(ids-idg);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    printf("%d",v.size());
}
int main(void) {
    process();
    return 0;
}