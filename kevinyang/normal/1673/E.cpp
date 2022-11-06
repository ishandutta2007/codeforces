#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>C(105,vector<int>(105));
vector<int>fact(2000005);
int lucas(int x, int y, int p){
    int v = fact[x]-fact[y]-fact[x-y];
    if(v==0)return 1;
    return 0;
}
void precalc(){
    for(int i = 1; i<=2000000; i++){
        int k = i;
        int cnt = 0;
        while(k%2==0){
            k/=2;
            cnt++;
        }
        fact[i] = fact[i-1]+cnt;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false); precalc();
    int n,k;
    cin >> n >> k;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<vector<int>>psa(30,vector<int>(n+5));
    for(int i = 0; i<=min(25LL,n); i++){
        for(int j = 0; j<=n-i; j++){
            psa[i][j] = lucas(n-i,j,2);
        }
        for(int j = 1; j<=n; j++){
            psa[i][j]+=psa[i][j-1];
        }
    }
    k = n-1-k;
    vector<int>ans(1<<20);
    for(int i = 1; i<=n; i++){
        int sum = -arr[i];
        int j = i;
        while(j<=n){
            sum+=arr[j];
            if(j-i>k)break;
            if(sum>=20)break;
            if(arr[i]*(1<<sum)>=(1<<20))break;
            int v = arr[i]*(1<<sum);
            int num = n-1-(j-i);
            if(i>1)num--;
            if(j<n)num--;
            int used = j-i;
            int val = psa[n-num][k-used];
            val%=2;
            if(val){
                ans[v]^=1;
            }
           // cout << v << " " << val << "\n";
            j++;
        }
    }
    int idx = 0;
    for(int i = (1<<20)-1; i>=0; i--){
        if(ans[i]>0){
            idx = i;
            break;
        }
    }
    for(int i = idx; i>=0; i--){
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}