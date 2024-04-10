#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
double ans;

vector<int> cg[505], cv[505];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        cg[A].push_back(B); cv[A].push_back(C);
        cg[B].push_back(A); cv[B].push_back(C);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<cg[i].size();j++) {
            double cur = ((double)(a[i]+a[cg[i][j]]))/cv[i][j];
            ans = max(cur,ans);
        }
    }
    printf("%.12lf",ans);
}