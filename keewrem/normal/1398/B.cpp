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
        cin >> s;
        N = s.size();
        vi v;
        int c = 0;
        for(auto x: s){
            if(x == '1')c++;
            else {if(c)v.pb(c); c=0;}
        }
        if(c)v.pb(c);
        sort(v.rbegin(),v.rend());
        c = 0;
        for(int i = 0; i < v.size(); i+=2)c+=v[i];
        cout << c <<"\n";
    }
    return 0;
}