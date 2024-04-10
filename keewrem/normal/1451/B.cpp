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
ll N,Q,a,b;
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> Q >>s;
        while(Q--){
            cin >> a >> b;
            a--; b--;
            bool ans = 0;
            for(int i = 0; i < a; i++)if(s[i]==s[a])ans=1;
            for(int i = b+1; i < N; i++)if(s[i]==s[b])ans=1;
            if(ans)cout <<"YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}