#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
vector < int > way[NS];
int q[NS], far[NS], f, r;
int arr[NS], from[NS], chk[NS];
int cnt[NS];

int main(){
//    freopen("input.txt", "r", stdin);

    scanf("%d", &N);
    for(int i=0;i<N-1;++i){
        int a, b; scanf("%d %d", &a, &b);
        way[a].push_back(b), way[b].push_back(a);
    }
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    q[r] = 1, far[r++] = 1, chk[1] = 1, ++cnt[0];
    while(f<r){
        for(int i=0;i<(int)way[q[f]].size();++i) if(!chk[way[q[f]][i]]){
            q[r] = way[q[f]][i], far[r++] = far[f]+1;
            from[way[q[f]][i]] = q[f], chk[way[q[f]][i]] = 1;
            ++cnt[q[f]];
        }
        ++f;
    }
    int pos = 0;
    for(int i=1;i<=N;++i){
        while(!cnt[arr[pos]]) ++pos;
        if(from[arr[i]]!=arr[pos]){
            puts("No");
            return 0;
        }
        --cnt[arr[pos]];
    }
    puts("Yes");

    return 0;
}