#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;
string S;

int main(){
    cin >> T;
    while(T--){
        cin >> S;
        int cnt[3] = {0,0,0};
        int k =  0;
        int l = 0;
        int res = S.size()+1;
        for(int i = 0; i < S.size(); i++){
            if(cnt[S[i]-'1']==0)k++; cnt[S[i]-'1']++;
            while(cnt[S[l]-'1']>1){
                cnt[S[l++]-'1']--;
            }
            if(k == 3){
                res = min(res,i-l+1);
            }
        }
        if(k == 3)cout << res <<"\n";
        else cout << 0 << "\n";
    }
    return 0;
}