#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,m,d;
int main(void) {
    int res=0;
    scanf("%d",&n);
    scanf("%d",&d);
    REP(i,n) {
        int v;
        scanf("%d",&v);
        q.push(v);
    }
    scanf("%d",&m);
    REP(i,m) {
        if (q.empty()) res-=d;
        else {
            res+=q.top();
            q.pop();
        }
    }
    printf("%d",res);
    return 0;
}