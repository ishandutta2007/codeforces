#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int id[MAX],pos[MAX];
int n,m,q;
void init(void) {
    scanf("%d%d%d",&n,&q,&m);
    REP(i,n) {
        scanf("%d",&id[i]);
        id[i]--;
        pos[id[i]]=i;
    }
}
void process(void) {
    long long res=0;
    REP(love,q) {
        int x;
        scanf("%d",&x);
        x--;
        res+=pos[x]/m+1;
        if (pos[x]>0) {
            int tmp=pos[x];
            swap(id[tmp],id[tmp-1]);
            pos[id[tmp]]=tmp;
            pos[id[tmp-1]]=tmp-1;
        }
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}