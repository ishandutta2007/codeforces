#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int k[30][100002];
void die(){printf("NO");exit(0);}
int l[100001],r[100001],v[100001],ans[100000];
int main() {
    int n,m,i,j,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d%d",l+i,r+i,v+i);
    for(i=0;i<m;i++){
        for(j=0;j<30;j++){
            int t=(v[i]>>j)&1;
            if(t)k[j][l[i]]++,k[j][r[i]+1]--;
        }
    }
    for(i=1;i<=n;i++)for(j=0;j<30;j++)k[j][i]+=k[j][i-1];
    for(i=1;i<=n;i++)for(j=0;j<30;j++)if(k[j][i])k[j][i]=1;
    for(i=1;i<=n;i++)for(j=0;j<30;j++)k[j][i]+=k[j][i-1];
    int diff;
    for(i=0;i<m;i++){
        for(j=0;j<30;j++){
            int t=(v[i]>>j)&1;
            if(!t&&k[j][r[i]]-k[j][l[i]-1]==r[i]-l[i]+1)die();
        }
    }
    for(i=0;i<n;i++)for(j=0;j<30;j++)ans[i]|=(k[j][i+1]-k[j][i])<<j;
    printf("YES\n");
    for(i=0;i<n;i++)printf("%d ",ans[i]);
}