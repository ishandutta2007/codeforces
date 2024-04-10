#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> a[100];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    sort(a, a + n);
    int j, sum = 0;
    for(j = 0; j < n && sum + a[j].first <= k; j++)
        sum += a[j].first;
    printf("%d\n", j);
    for(int i = 0; i < j; i++)
        printf("%d ", a[i].second);
}