#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define INF 0x7fffffff
using namespace std;
ll n,m,dist[4][1005][1005],cx,cy,cur;
ll m12=INF,m13=INF,m23=INF,ans=INF;
ll dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
char mp[1005][1005];
queue<pair<ll,ll> >q[4];
bool flag;

bool valid(ll X,ll Y,ll Z) {
    if(X<0 || X>=n) return false;
    if(Y<0 || Y>=m) return false;
    if(mp[X][Y]=='#') return false;
    if(dist[Z][X][Y]!=-1) return false;
    return true;
}

int main()
{
    ll i,j,k;
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",&mp[i]);
    }
    for(k=1;k<4;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(mp[i][j]-'0'==k) {
                    q[k].push({i,j});
                }
                else dist[k][i][j]=-1;
            }
        }
    }
    for(k=1;k<4;k++) {
        while(!q[k].empty()) {
            cx=q[k].front().f;
            cy=q[k].front().s;
            q[k].pop();
            for(i=0;i<4;i++) {
                if(valid(cx+dx[i],cy+dy[i],k)) {
                    dist[k][cx+dx[i]][cy+dy[i]]=dist[k][cx][cy]+1;
                    q[k].push({cx+dx[i],cy+dy[i]});
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            flag=false;
            cur=0;
            for(k=1;k<4;k++) {
                if(dist[k][i][j]==-1) flag=true;
                cur+=dist[k][i][j];
            }
            if(flag)continue;
            ans=min(ans,cur-2);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(dist[1][i][j]==-1 || dist[2][i][j]==-1) continue;
            m12=min(m12,dist[1][i][j]+dist[2][i][j]-1);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(dist[2][i][j]==-1 || dist[3][i][j]==-1) continue;
            m23=min(m23,dist[2][i][j]+dist[3][i][j]-1);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(dist[1][i][j]==-1 || dist[3][i][j]==-1) continue;
            m13=min(m13,dist[1][i][j]+dist[3][i][j]-1);
        }
    }
    ans=min(ans,min(min(m12+m13,m12+m23),m13+m23));
    if(ans==INF) {puts("-1");return 0;}
    printf("%I64d",ans);
}