#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int N = 14;
LL arr[14];
LL sol[14], cnt, ans, gap;

int main(){
//    freopen("input.txt", "r", stdin);

    for(int i=0;i<14;i++){
        cin >> arr[i];
    }
    for(int k=0;k<14;k++){
        if(arr[k]){
            for(int i=0;i<14;i++) sol[i] = arr[i];
            gap = arr[k];
            sol[k] = 0;
            for(int j=0;j<14;j++){
                if(gap>=(j+14-k-1)%14+1) sol[j] += ((gap-(j+14-k-1)%14)-1)/14+1;
            }
            cnt = 0;
            for(int j=0;j<14;j++) if(sol[j]%2==0) cnt += sol[j];
            ans = max(cnt, ans);
        }
    }

    cout << ans;

    return 0;
}