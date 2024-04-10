#include<bits/stdc++.h>
using namespace std;
#define int ll
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N,K;
string s;

signed main(){
    cin >> T;
    while(T--){
        cin >> N >> K >> s;
        bool res = 1;
        for(int i = 0; i < K; i++){
            char q = '?';
            for(int j = i; j < N; j+= K){
                if(s[j]!='?' && q=='?')q = s[j];
                if(q != '?' && s[j]!=q && s[j]!='?')res = 0;
            }
            for(int j = i; j < N; j+= K){
                s[j] = q;
            }
        }
        int c=0, d= 0;
        for(int i =0; i < K;i++){
            if(s[i]=='1')c++;
            if(s[i]=='0')d++;
        }
        if(c > K/2 || d > K/2)res=0;
        if(res)cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;

}