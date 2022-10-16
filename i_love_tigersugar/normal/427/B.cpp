#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX];
int n,lim,c;
void process(void) {
    scanf("%d%d%d",&n,&lim,&c);
    FOR(i,1,n) scanf("%d",&a[i]);
    int res=0;
    deque<int> dq;
    FOR(i,1,n) {
        while (!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && dq.front()<=i-c) dq.pop_front();
        if (i>=c && a[dq.front()]<=lim) res++;
    }
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}