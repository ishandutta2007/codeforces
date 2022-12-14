#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2004];
int cnt[2004], acnt, val;
vector < int > vc;
int ans;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", arr + i);
        vc.push_back(arr[i]);
    }
    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end());
    for(int i = 1; i <= N; ++i){
        arr[i] = lower_bound(vc.begin(), vc.end(), arr[i]) - vc.begin() + 1;
        ++cnt[arr[i]];
        if(cnt[arr[i]] == 2) ++acnt;
    }
    ans = (int)1e9;
    if(val == acnt) ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; ++j){
            --cnt[arr[j]];
            if(cnt[arr[j]] == 1) ++val;
            if(val == acnt && j - i + 1 < ans){
                ans = j - i + 1;
            }
        }
        for(int j = i; j <= N; ++j){
            ++cnt[arr[j]];
        }
        val = 0;
    }
    printf("%d\n", ans);
    return 0;
}