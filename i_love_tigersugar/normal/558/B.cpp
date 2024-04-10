#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
vector<int> pos[MAX];
int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void process(void) {
    FOR(i,1,nextInt()) pos[nextInt()].push_back(i);
    int maxApp=0;
    REP(i,MAX) maxApp=max(maxApp,(int)pos[i].size());
    int l=0;
    int r=MAX;
    REP(i,MAX) if (pos[i].size()==maxApp) {
        int x=pos[i].front();
        int y=pos[i].back();
        if (y-x<r-l) {
            l=x;r=y;
        }
    }
    printf("%d %d\n",l,r);
}
int main(void) {
    process();
    return 0;
}