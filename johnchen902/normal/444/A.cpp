#include <cstdio>
#include <algorithm>
int data[500];
using namespace std;
int main(){
    int n, m;
    double maxi = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", data + i);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        maxi = max(maxi, (data[a] + data[b]) / (double) c);
    }
    printf("%.15f\n", maxi);
}