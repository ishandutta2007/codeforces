#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int N;
vector < int > way[NS];
int cnt[NS];

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; ++i){
        int a, b; scanf("%d %d", &a, &b);
        ++cnt[a], ++cnt[b];
        way[a].push_back(b), way[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i){
        if(cnt[i] == 1){
            continue;
        }
        if(cnt[i] == 2){
            puts("NO"); return 0;
        }
    }
    puts("YES");
    return 0;
}