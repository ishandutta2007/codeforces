#include <cstdio>
#include <algorithm>
using namespace std;

int n, s;
int st[31], ed[31];

int main(){
    scanf("%d %d",&n,&s);
    int edsum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d %d",&st[i],&ed[i]);
        s -= st[i];
        ed[i] -= st[i];
        edsum += ed[i];
    }
    if(s > edsum || s < 0){
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=0; i<n; i++) {
        printf("%d ",min(ed[i],s) + st[i]);
        s -= min(ed[i],s);
    }
}