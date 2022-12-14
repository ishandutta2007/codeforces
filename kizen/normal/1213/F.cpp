#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
int N, k;
int p[NS], q[NS];
int val[NS];
vector < pair < int, int > > vc;
char ans[NS];
int now;

int main(){
    scanf("%d %d", &N, &k);
    for(int i = 1; i <= N; ++i){
        scanf("%d", p + i);
        val[p[i]] = i;
    }
    for(int i = 1; i <= N; ++i){
        scanf("%d", q + i);
        if(i > 1){
            if(val[q[i - 1]] > val[q[i]]){
                vc.push_back(make_pair(val[q[i]], val[q[i - 1]]));
            }
        }
    }
    sort(vc.begin(), vc.end());
    int big = 0;
    if((int)vc.size()){
        int gap = (int)vc.size() - 1;
        for(int i = vc[(int)vc.size() - 1].second + 1; i <= N; ++i) vc.push_back(make_pair(i, i));
        for(int i = 1; i < vc[0].first; ++i) vc.push_back(make_pair(i, i));
        for(int i = 0; i < gap; ++i){
            for(int j = vc[i].second + 1; j < vc[i + 1].first; ++j) vc.push_back(make_pair(j, j));
        }
    }
    else{
        for(int i = 1; i <= N; ++i) vc.push_back(make_pair(i, i));
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < (int)vc.size(); ++i){
        if(!i || vc[i].first > big){
            now = min(now + 1, 26);
        }
        for(int j = max(vc[i].first, big + 1); j <= vc[i].second; ++j){
            ans[p[j]] = 'a' + now - 1;
        }
        big = max(big, vc[i].second);
    }
    if(now >= k){
        puts("YES");
        printf("%s", ans + 1);
    }
    else{
        puts("NO");
    }
    return 0;
}