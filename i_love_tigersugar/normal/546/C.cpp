#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int maxTime=(int)1e7;
deque<int> dq1,dq2;
void init(void) {
    int n,k1,k2;
    scanf("%d%d",&n,&k1);
    REP(love,k1) {
        int x;
        scanf("%d",&x);
        dq1.push_back(x);
    }
    scanf("%d",&k2);
    REP(love,k2) {
        int x;
        scanf("%d",&x);
        dq2.push_back(x);
    }
}
void process(void) {
    int cnt=0;
    while (true) {
        if (dq1.empty()) {
            printf("%d %d\n",cnt,2);
            return;
        }
        if (dq2.empty()) {
            printf("%d %d\n",cnt,1);
            return;
        }
        if (cnt>=maxTime) {
            printf("-1\n");
            return;
        }
        cnt++;
        int x1=dq1.front();dq1.pop_front();
        int x2=dq2.front();dq2.pop_front();
        if (x1>x2) {
            dq1.push_back(x2);
            dq1.push_back(x1);
        } else {
            dq2.push_back(x1);
            dq2.push_back(x2);
        }
    }
}
int main(void) {
    init();
    process();
    return 0;
}