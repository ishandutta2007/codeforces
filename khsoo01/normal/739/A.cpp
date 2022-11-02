#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m;
pair<int,int> a[100005];

int main()
{
    scanf("%d%d",&n,&m);
    int mitv = inf;
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        mitv = min(mitv, a[i].second - a[i].first + 1);
    }
    printf("%d\n",mitv);
    for(int i=1;i<=n;i++) {
        printf("%d ",i%mitv);
    }
}