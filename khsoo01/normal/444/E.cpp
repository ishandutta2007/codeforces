#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, val[3005], cap[3005], sz[3005], cc;
bool vis[3005];

vector<int> cg[3005];
vector<pair<int,pair<int,int> > >edg;

queue<pair<int,int> > acv;

void trav (int cur) {
    if(vis[cur]) return;
    cap[cc] += val[cur];
    sz[cc]++;
    vis[cur] = true;
    for(int i=0;i<cg[cur].size();i++) {
        trav(cg[cur][i]);
    }
}

bool can (int piv) {
    for(int i=0;i<cc;i++) {
        cap[i] = 0; sz[i] = 0;
    }
    cc = 0;
    for(int i=1;i<=n;i++) {
        cg[i].clear();
        vis[i] = false;
    }
    for(int i=0;i<edg.size() && edg[i].X<piv;i++) {
        cg[edg[i].Y.X].push_back(edg[i].Y.Y);
        cg[edg[i].Y.Y].push_back(edg[i].Y.X);
    }
    int capsum = 0;
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        trav(i);
        capsum += cap[cc]; cc++;
    }
    while(!acv.empty()) acv.pop();
    int szsum = 0;
    for(int i=0;i<cc;i++) {
        if(capsum-szsum-cap[i]<sz[i]) {
            acv.push({i,capsum-sz[i]-szsum});
            if(capsum-sz[i]-szsum<0) return false;
        }
        szsum += sz[i];
    }
    for(int i=0;i<cc;i++) {
        int lft = sz[i];
        while(!acv.empty()) {
            int cur = acv.front().X;
            int goal = acv.front().Y;
            if(cur<=i) return false;
            if(cap[cur]-goal>lft) {
                cap[cur] -= lft;
                lft = 0;
                break;
            }
            else {
                lft -= cap[cur]-goal;
                cap[cur] = goal;
                acv.pop();
            }
        }
        for(int j=0;j<cc;j++) {
            if(i==j) continue;
            if(cap[j]>=lft) {
                cap[j] -= lft;
                lft = 0;
                break;
            }
            else {
                lft -= cap[j];
                cap[j] = 0;
            }
        }
        if(lft) return false;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        edg.push_back({C,{A,B}});
    }
    sort(edg.begin(),edg.end());
    for(int i=1;i<=n;i++) {
        scanf("%d",&val[i]);
    }
    int S = 0, E = 10000;
    while(S<E) {
        int piv = (S+E)/2+1;
        if(can(piv)) S = piv;
        else E = piv-1;
    }
    printf("%d",S);
}