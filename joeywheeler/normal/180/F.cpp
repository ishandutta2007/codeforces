#include <cstdio>

const int MAX_N = 100005;

int N;
int prev[MAX_N];
int p[MAX_N];

int main() {
    scanf("%d",&N);

    for(int i=0;i<N;i++) {
        int a;
        scanf("%d",&a);
        a--;
        prev[a] = i;
    }

    for(int i=0;i<N;i++) {
        int a;
        scanf("%d",&a);
        a--;
        printf("%d ",prev[a]+1);
    }

    printf("\n");
    return 0;
}