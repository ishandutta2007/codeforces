#include<bits/stdc++.h>
using namespace std;
int n, a[300005], sz[300005], ans, cnt;
char val[300005];

map<char, int> chi[300005];
vector<int> cg[300005];

int Merge (int Big, int Small) {
    int delta = 0;
    for(auto &CC : chi[Small]) {
        int C = CC.second;
        if(chi[Big][val[C]]) {
            int tmp = chi[Big][val[C]];
            if(sz[C] > sz[tmp]) {
                chi[Big][val[C]] = C;
                delta += sz[C] - sz[tmp] + Merge(C, tmp);
            }
            else delta += Merge(tmp, C);
        }
        else {
            chi[Big][val[C]] = C;
            delta += sz[C];
        }
    }
    sz[Big] += delta;
    return delta;
}

void solve (int cur, int prev) {
    sz[cur] = 1;
    for(auto &C : cg[cur]) {
        if(C == prev) continue;
        solve(C, cur);
        if(chi[cur][val[C]]) {
            int A = C, B = chi[cur][val[C]];
            if(sz[A] > sz[B]) {
                chi[cur][val[C]] = A;
                sz[cur] += sz[A] - sz[B] + Merge(A, B);
            }
            else sz[cur] += Merge(B, A);
        }
        else {
            chi[cur][val[C]] = C;
            sz[cur] += sz[C];
        }
    }
    if(ans < sz[cur] + a[cur]) {
        ans = sz[cur] + a[cur];
        cnt = 0;
    }
    if(ans == sz[cur] + a[cur]) cnt++;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%s",val+1);
    for(int i=1;i<n;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        cg[A].push_back(B);
        cg[B].push_back(A);
    }
    solve(1, -1);
    printf("%d\n%d\n",ans,cnt);
}