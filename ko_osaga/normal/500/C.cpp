#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,w[505],b[1005];

int ord[505], vis[505], piv, res;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&w[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }
    for (int i=0; i<m; i++) {
        if(!vis[b[i]]) ord[piv++] = b[i];
        vis[b[i]] = 1;
    }
    for (int i=1; i<n; i++) {
        if(!vis[i]) ord[piv++] = i;
    }
    for (int i=0; i<m; i++) {
        int loc = (int)(find(ord,ord+n,b[i]) - ord);
        for (int j=0; j<loc; j++) {
            res += w[ord[j]];
        }
        for (int j=loc;j ; j--) {
            ord[j] = ord[j-1];
        }
        ord[0] = b[i];
        
    }
    printf("%d",res);
}