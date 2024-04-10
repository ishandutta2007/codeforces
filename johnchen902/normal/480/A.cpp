#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair<int, int> a[5000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    sort(a, a + n);
    int day = 0;
    for(int i = 0; i < n; i++) {
        if(day <= a[i].second)
            day = a[i].second;
        else
            day = a[i].first;
    }
    printf("%d\n", day);
}