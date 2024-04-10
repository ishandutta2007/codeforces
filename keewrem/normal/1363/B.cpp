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
int N;
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        int uni = 0;
        for(auto x: s)if(x=='1')uni++;
        int ans = min(uni,(int)s.size()-uni);
        N = s.size();
        int presi = 0;
        for(int i = 0; i < N; i++){
            presi+=s[i]-'0'; uni-=s[i]-'0';
            ans = min(ans,min(i+1-presi+uni,presi-uni+N-i-1));
        }
        cout << ans <<"\n";
    }
    return 0;
}