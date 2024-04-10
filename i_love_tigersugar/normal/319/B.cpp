#include<cstdio>
#include<vector>
#include<queue>
#define MAX   100100
using namespace std;
queue<int> q;
vector<int> del;
int h[MAX];
bool exist[MAX];
int next[MAX];
int prev[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i=i+1) {
        exist[i]=true;
        next[i]=i+1;
        prev[i]=i-1;
        scanf("%d",&h[i]);
    }
    exist[0]=false;
    exist[n+1]=false;
}
void process(void) {
    int i,j,l,r,res;
    res=0;
    while (!q.empty()) q.pop();
    del.clear();
    for (i=1;i<n;i=i+1)
        if (h[i]>=h[i+1]) q.push(i);
    while (true) {
        if (q.empty()) {
            printf("%d",res);
            return;
        }
        res++;
        del.clear();
        while (!q.empty()) {
            j=q.front();q.pop();
            del.push_back(next[j]);
            exist[next[j]]=false;
        }
        for (j=0;j<del.size();j=j+1) {
            l=prev[del[j]];
            r=next[del[j]];
            prev[r]=l;
            next[l]=r;
            if (exist[l] && exist[r] && h[l]>=h[r]) q.push(l);
        }
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("TREELINE.INP","r",stdin);
    freopen("TREELINE.OUT","w",stdout);
#endif
    init();
    process();
    return 0;
}