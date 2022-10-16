#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
const int goal=(int)1e6;
struct town {
    int x,y,v;
    town() {
        x=y=v=0;
    }
    void input(void) {
        scanf("%d%d%d",&x,&y,&v);
    }
    bool operator < (const town &t) const {
        return (x*x+y*y<t.x*t.x+t.y*t.y);
    }
};
town a[MAX];
void process(void) {
    int n,s;
    scanf("%d%d",&n,&s);
    FOR(i,1,n) a[i].input();
    sort(a+1,a+n+1);
    FOR(i,1,n) {
        if (s+a[i].v>=goal) {
            printf("%.7lf",sqrt(a[i].x*a[i].x+a[i].y*a[i].y));
            return;
        }
        else s+=a[i].v;
    }
    printf("-1");
}
int main(void) {
    process();
    return 0;
}