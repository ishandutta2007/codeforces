#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
int T;
ll N;
 
int main() {
    cin >> N;
    vi v(N+1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];
 
    vi s = v;
    for(int i = 2; i <= N; i++){
        s[i]+=s[i-1];
    }
    s[0] = 0;
    int ans = 0;
    for(int k = -30; k <= 30; k++){
        int st = 0, bb = 0, nu = 0,cnt = 0;
        for(int i = 1; i <= N;i++){
            cnt+=(v[i]==k);
            if(cnt && v[i] <= k)ans = max(ans,s[i]-s[st]-k-bb);
            if(v[i] > k){st = i; bb = 0; nu = 0;cnt = 0;}
            nu = min(s[i]-s[st],nu);
            if(i < N && v[i+1]==k)bb = min(bb,nu);
            
        }
 
    }
    cout << ans << "\n";
    return 0;
}