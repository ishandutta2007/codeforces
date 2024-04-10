#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
bool used[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    int res=0;
    FOR(i,1,n) {
        while (used[a[i]]) {
            res++;
            a[i]++;
        }
        used[a[i]]=true;
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}