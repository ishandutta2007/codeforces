#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(int x){
    if(x == 1){
        return false;
    }
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
signed main(){
    int n;
    cin >> n;
    n-= 1;
    vector<int> ans(n,1);
    int tmp = 1;
    for(int i = 0;i < n;i++){
        int a = i + 2;
        if(f(a)){
            ans[i] = tmp;
            tmp++;
            continue;
        }
        else{
            for(int j = 2;j * j <= a;j++){
                if(a % j == 0){
                    ans[i] = ans[j - 2];
                    break;
                }
            }
        }
    }
    for(int i =0;i < n;i++){
        cout << ans[i] << " ";
    }


}