#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL NS = (2e5)+4, INF = (2e9);
LL N;
LL arr[NS];
map < LL, LL > mp;
vector < LL > ans;

int main(){
    LL i, j;
    scanf("%I64d", &N);
    for(i=1;i<=N;i++) scanf("%I64d", arr+i), mp[arr[i]] = 1;

    for(i=1;i<=N;i++){
        for(j=1;j<=INF;j*=2) if(mp.find(arr[i]+j)!=mp.end()&&mp.find(arr[i]-j)!=mp.end()){
            ans.push_back(arr[i]), ans.push_back(arr[i]+j), ans.push_back(arr[i]-j); break;
        }
        if((LL)ans.size()==3) break;
    }
    if((LL)ans.size()!=3){
        for(i=1;i<=N;i++){
            for(j=1;j<=INF;j*=2) if(mp.find(arr[i]+j)!=mp.end()){
                ans.push_back(arr[i]), ans.push_back(arr[i]+j); break;
            }
            if((LL)ans.size()==2) break;
        }
        if((LL)ans.size()!=2){
            ans.push_back(arr[1]);
        }
    }

    printf("%I64d\n", (LL)ans.size());
    for(i=0;i<(LL)ans.size();i++) printf("%I64d ", ans[i]);

    return 0;
}