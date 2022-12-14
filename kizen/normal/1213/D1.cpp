#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
int N, k;
vector < int > vc[NS];

int main(){
    scanf("%d %d", &N, &k);
    for(int i = 1; i <= N; ++i){
        int num; scanf("%d", &num);
        int cnt = 0;
        while(1){
            vc[num].push_back(cnt);
            if(!num) break;
            num >>= 1, ++cnt;
        }
    }
    int ans = (int)1e9;
    for(int i = 0; i < NS; ++i){
        sort(vc[i].begin(), vc[i].end());
        if((int)vc[i].size() >= k){
            int sum = 0;
            for(int j = 0; j < k; ++j){
                sum += vc[i][j];
            }
            ans = min(ans, sum);
        }
    }
    printf("%d\n", ans);
    return 0;
}