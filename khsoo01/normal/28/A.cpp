#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int n,m,a[505][2],dt[505];
int c1[200005][2], c2[200005][2];
bool flag;
vector<int>cnt[200005];

int dist (int A,int B) {
    return abs(a[A][0]-a[B][0]) + abs(a[A][1]-a[B][1]);
}

int main()
{
    ll i,j,tmp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    a[n][0] = a[0][0]; a[n][1] = a[0][1];
    a[n+1][0] = a[1][0]; a[n+1][1] = a[1][1];
    for(i=1;i<=m;i++) {
        scanf("%d",&tmp);
        cnt[tmp].push_back(i);
    }
    for(i=2;i<=n;i+=2) {
        tmp = dist(i,i-2);
        if(++c1[tmp][0]>cnt[tmp].size()) flag = true;
    }
    if(!flag) {
        puts("YES");
        for(i=2;i<=n;i+=2) {
            tmp = dist(i,i-2);
            printf("-1 %d ",cnt[tmp][c1[tmp][1]++]);
        }
        return 0;
    }
    flag = false;
    for(i=3;i<=n+1;i+=2) {
        tmp = dist(i,i-2);
        if(++c2[tmp][0]>cnt[tmp].size()) flag = true;
    }
    if(!flag) {
        puts("YES");
        tmp = dist(n+1,n-1);
        printf("%d -1 ",cnt[tmp][c2[tmp][1]++]);
        for(i=3;i<n;i+=2) {
            tmp = dist(i,i-2);
            printf("%d -1 ",cnt[tmp][c2[tmp][1]++]);
        }
        return 0;
    }
    puts("NO");
}