#include<bits/stdc++.h>
using namespace std;
bool vis[510];
int num[510] , wei[510];
int main(){
    int N , M , ans = 0 , end = 0;
    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i)
        cin >> wei[i];
    for(int i = 1 ; i <= M ; ++i){
        int a;
        cin >> a;
        if(!vis[a]){
            vis[a] = 1;
            for(int j = end ; j ; --j){
                num[j + 1] = num[j];
                ans += wei[num[j]];
            }
            num[1] = a;
            ++end;
        }
        else{
            for(int j = 1 ; j <= end ; ++j)
                if(num[j] == a){
                    for(int k = j - 1 ; k ; --k){
                        num[k + 1] = num[k];
                        ans += wei[num[k]];
                    }
                    num[1] = a;
                    break;
                }
        }
    }
    cout << ans;
    return 0;
}