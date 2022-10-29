#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int a[500010];
set<int>s1;
set<pii>s2;

int main() {
    int Q;
    scanf("%d",&Q);
    int cnt = 0;
    while(Q--) {
        int tp, v;
        scanf("%d",&tp);
        if (tp == 1) {
            scanf("%d",&a[++cnt]);
            s1.insert(cnt);
            s2.insert(pii(-a[cnt], cnt));
        } else if (tp == 2) {
            int id = (*s1.begin());
            printf("%d ",id);
            s1.erase(id);
            s2.erase(pii(-a[id], id));
        } else {
            int id = (*s2.begin()).second;
            printf("%d ",id);
            s1.erase(id);
            s2.erase(pii(-a[id], id));
        }
    }
}