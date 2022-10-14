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
    while(T--){
        string s;
        cin >> s;
        for(auto &x: s)x-='A';
        int c = 0, ans = 0;
        for(auto x: s){
            if(x==1){
                if(c>0)ans+=2;
                else ans++;
            }
            if(x==0)c++;
            else c--;
            c=max(c,0);

        }cout << (int)s.size()-(ans-(ans%2))<<"\n";

    }
    return 0;
}