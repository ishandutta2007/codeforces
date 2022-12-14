#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int N;
pair < int, int > in[NS];
vector < int > ans;
vector < pair < int, int > > ans2;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &in[i - 1].first);
        in[i - 1].second = i * 2 - 1;
    }
    sort(in, in + N);
    reverse(in, in + N);
    ans.resize(N);
    for(int i = 0; i < N; ++i){
        ans[i] = in[i].second;
    }
    for(int i = 0; i < N; ++i){
        if(in[i].first + i == (int)ans.size()) ans.push_back(in[i].second + 1);
        else ans2.push_back(make_pair(in[i].second + 1, ans[i + in[i].first - 1]));
    }
    for(int i = 0; i < (int)ans.size() - 1; ++i){
        printf("%d %d\n", ans[i], ans[i + 1]);
    }
    for(auto&i:ans2){
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}