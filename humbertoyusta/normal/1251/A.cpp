#include<bits/stdc++.h>
#define maxn 100010
#define mod 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

string s, ans;
int cnt[505];
map<char,int> mp;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    int tc;
    cin >> tc;
    while( tc-- ){
        ans.clear();
        mp.clear();

        cin >> s;

        for(int i=0; i<s.size(); i++){
            cnt[i] = 1;
            if( i >= 1 )
                if( s[i-1] == s[i] )
                    cnt[i] += cnt[i-1];
            if( i == s.size() - 1){
                if( cnt[i] % 2 == 1 && !mp[s[i]] ){
                    ans += s[i];
                    mp[s[i]] = 1;
                }
                break;
            }
            if( cnt[i] % 2 == 1 && s[i] != s[i+1] && !mp[s[i]] ){
                ans += s[i];
                mp[s[i]] = 1;
            }
        }

        sort(ans.begin(),ans.end());
        cout << ans << '\n';
    }

    return 0;
}