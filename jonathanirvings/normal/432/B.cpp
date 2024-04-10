#include <bits/stdc++.h>
using namespace std;

int home[100005], away[100005];
pair<int,int> kit[100005];
int n;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&kit[i].first,&kit[i].second);
        ++home[kit[i].first];
        ++away[kit[i].second];
    }
    for (int i = 0; i < n; ++i) {
        int a = (n - 1) - home[kit[i].second];
        int h = 2 * (n - 1) - a;
        printf("%d %d\n",h,a);
    }
}