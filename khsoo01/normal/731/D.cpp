#include<bits/stdc++.h>
using namespace std;
int n, c, cnt[1000005], tot;
vector<int> seq[500005];

int reord (int val, int piv) {return (val-piv+c)%c;}

void solve (int S, int E, int D) {
    if(S >= E) return;
    int i = S, cs, fr = -1;
    while(seq[i].size() <= D && i <= E) i++;
    if(i>E) return;
    cs = i;
    for(;i<=E;i++) {
        if(seq[i].size() <= D) {puts("-1"); exit(0);}
        if(fr == -1) fr = seq[i][D];
        else if(reord(seq[i-1][D], fr) > reord(seq[i][D], fr)) {
            puts("-1"); exit(0);
        }
        else if(reord(seq[i-1][D], fr) < reord(seq[i][D], fr)) {
            solve(cs, i-1, D+1); cs = i;
        }
    }
    solve(cs, E, D+1);
    tot++;
    int as = (c + 1 - fr), ae = (as + (c - 1 - reord(seq[E][D], fr)))%c;
    cnt[as]++; cnt[ae+1]--;
    if(as > ae) cnt[0]++;
}

int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++) {
        int M;
        scanf("%d",&M);
        for(int j=1;j<=M;j++) {
            int tmp;
            scanf("%d",&tmp);
            seq[i].push_back(tmp);
        }
    }
    solve(1, n, 0);
    int cur = 0;
    for(int i=0;i<c;i++) {
        cur += cnt[i];
        if(cur == tot) {printf("%d\n",i); return 0;}
    }
    puts("-1");
}