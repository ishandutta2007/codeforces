#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pi;


struct seg{int s, e, x, y;};

int n, m;
seg a[100005];
seg b[100005];

bool cmpa(seg a, seg b){
    if(a.s != b.s) return a.s < b.s;
    return a.e > b.e;
}


multimap<int,pi> mp;

int match[100005];
int main(){
    memset(match,-1,sizeof(match));
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].s,&a[i].e);
        a[i].x = i;
    }
    sort(a,a+n,cmpa);
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&b[i].s,&b[i].e,&b[i].y);
        b[i].x = i+1;
    }
    sort(b,b+m,cmpa);
    int st = 0;
    for (int i=0; i<n; i++) {
        while (st < m && b[st].s <= a[i].s) {
            mp.insert(make_pair(b[st].e,pi(b[st].x,b[st].y)));
            // insert!
            st++;
        }
        auto t = mp.lower_bound(a[i].e);
        if(t == mp.end()){
            puts("NO");
            return 0;
        }
        match[a[i].x] = t->second.first;
        t->second.second--;
        if(t->second.second == 0){
            mp.erase(t);
        }
    }
    puts("YES");
    for (int i=0; i<n; i++) {
        printf("%d ",match[i]);
    }
}