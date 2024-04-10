#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,K,T,M;
bool tolto[500010];
int ans[500010];
int main(){
    cin >> N;
    int curr = N/2;
    int sus = curr*2;
    for(int i = N; i >= 2; i--){
        while(tolto[sus]&&curr>1){
            sus-=curr;
            if(sus==curr){
                if(curr>1)curr--; sus = N-(N%curr);
            }
        }
        tolto[sus]=1;
        ans[i]=curr;
    }
    for(int i = 2; i <=N; i++)cout << ans[i]<<" ";
    return 0;
}