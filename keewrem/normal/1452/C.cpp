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

int main(){
    cin >> T;
    string s;
    while(T--){
        cin >> s; N = s.size();
        int o = 0, oo = 0, ans = 0;
        for(auto x: s){
            if(x=='(')o++;
            if(x==')' && o > 0){o--;ans++;}
            if(x=='[')oo++;
            if(x==']' && oo > 0){oo--;ans++;}
        }
        cout << ans <<"\n";
    }
    return 0;
}