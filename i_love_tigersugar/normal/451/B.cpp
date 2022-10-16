#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    vector<int> v;
    FOR(i,1,n) v.push_back(a[i]);
    sort(v.begin(),v.end());
    FOR(i,1,n) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
}
void process(void) {
    bool ok=true;
    FOR(i,1,n) if (a[i]!=i) ok=false;
    if (ok) {
        printf("yes\n1 1");
        return;
    }
    int l=1;
    int r=n;
    while (l<n && a[l]==l) l++;
    while (r>1 && a[r]==r) r--;
    reverse(a+l,a+r+1);
    FOR(i,1,n) if (a[i]!=i) {
        printf("no");
        return;
    }
    printf("yes\n%d %d",l,r);
}
int main(void) {
    init();
    process();
    return 0;
}