#include <cstdio>

int n,m;
int a[105][105];
char str[105][105];

void paint(int p, int q, int x){
    for (int i=0; i<=p; i++) {
        for (int j=0; j<=q; j++) {
            a[i][j]+=x;
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            a[i][j] = (str[i][j] == 'B' ? 1 : -1);
        }
    }
    int ret = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if(a[i][j] != 0){
                paint(i,j,-a[i][j]);
                ret++;
            }
        }
    }
    printf("%d",ret);
}