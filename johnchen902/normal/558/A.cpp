#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int x[100];
int a[100];
bool collected[100];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", x + i, a + i);
    int ans1 = 0;
    while(true) {
        {
            int j = -1;
            for(int i = 0; i < n; i++)
                if(x[i] > 0 && !collected[i] && (j == -1 || x[i] < x[j]))
                    j = i;
            if(j == -1)
                break;
            collected[j] = true;
            ans1 += a[j];
        }
        {
            int j = -1;
            for(int i = 0; i < n; i++)
                if(x[i] < 0 && !collected[i] && (j == -1 || x[j] < x[i]))
                    j = i;
            if(j == -1)
                break;
            collected[j] = true;
            ans1 += a[j];
        }
    }
    for(int i = 0; i < n; i++)
        collected[i] = false;
    int ans2 = 0;
    while(true) {
        {
            int j = -1;
            for(int i = 0; i < n; i++)
                if(x[i] < 0 && !collected[i] && (j == -1 || x[j] < x[i]))
                    j = i;
            if(j == -1)
                break;
            collected[j] = true;
            ans2 += a[j];
        }
        {
            int j = -1;
            for(int i = 0; i < n; i++)
                if(x[i] > 0 && !collected[i] && (j == -1 || x[i] < x[j]))
                    j = i;
            if(j == -1)
                break;
            collected[j] = true;
            ans2 += a[j];
        }
    }
    printf("%d\n", ans1 > ans2 ? ans1 : ans2);
}