#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, k;
int arr[NS], cnt[NS], can;
vector < int > ans;

int main(){
    scanf("%d %d", &N, &k);
    for(int i=1;i<=N;++i) scanf("%d", arr+i), ++cnt[arr[i]];
    int a = 1, b = NS, mid;
    while(a<b){
        mid = (a+b)/2+1;
        can = 0;
        for(int i=0;i<NS;++i){
            can += cnt[i]/mid;
        }
        if(can>=k){
            a = mid;
        }
        else b = mid-1;
    }
    for(int i=0;i<NS;++i){
        while((int)ans.size()<k&&cnt[i]>=a){
            cnt[i] -= a;
            ans.push_back(i);
        }
    }
    for(int i=0;i<(int)ans.size();++i) printf("%d ", ans[i]);
    return 0;
}