#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
int arr[NS], val[NS], cnt[NS], par[NS];
vector < int > way[NS];
int q[NS], f, r, chk[NS], cval[NS];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    for(int i=2;i<=N;++i){
        int num; scanf("%d", &num); way[num].push_back(i); ++cnt[num];
        par[i] = num;
    }
    for(int i=1;i<=N;++i) if(!cnt[i]) q[r++] = i;
    for(int i=0;i<NS;++i) cval[i] = i;
    int gap = r;
    while(f<r){
        if(arr[q[f]]==1){
            for(auto&nxt:way[q[f]]) val[q[f]] = max(val[q[f]], val[nxt]);
        }
        else{
            val[q[f]] = gap+1;
            for(auto&nxt:way[q[f]]) val[q[f]] -= gap-val[nxt]+1;
        }
        if(!(int)way[q[f]].size()) val[q[f]] = gap;
        --cnt[par[q[f]]];
        if(!cnt[par[q[f]]]) q[r++] = par[q[f]];
        ++f;
    }
    printf("%d\n", val[1]);
    return 0;
}