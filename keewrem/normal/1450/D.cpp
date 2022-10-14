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

int T = 1;
ll N,K;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        vi p(N+1,0);
        for(auto &x: v){cin >> x;p[x]++;}
        int l = 0, r = N-1;

        string ans(N,'0');
        int k;
        for(int i = 0; i < N-1; i++){
            k = 0;
            if(i == 0)k = 1;
            else{
            if(v[l]==i){l++;k++;}
            if(v[r]==i){r--;k++;}
            }
            if(k == 1 && p[i+1] && (p[i] == 1||i == 0)&& (ans[N-i]=='1'||i==0))ans[N-i-1] = '1';
        }
        ans[0] = '1';
        for(int i = 1; i <= N; i++)if(p[i]!=1)ans[0]='0';
        cout << ans <<"\n";
        //caso N a parte

    }
    return 0;
}