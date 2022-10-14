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
        cin >> N;
        vi v(N);
        int s = 0;
        for(auto &x: v){cin >> x; s+=x;}
        if(s == 0){cout << "NO\n"; continue;}
        sort(v.begin(),v.end());
        if(s > 0)reverse(v.begin(),v.end());
        cout << "YES\n";
        for(auto x: v)cout << x <<" ";
        cout << "\n";

    }
    return 0;
}