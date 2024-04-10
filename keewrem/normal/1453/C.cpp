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
#define int ll
int T = 1;
ll N;

signed main(){
    cin >> T;
    while(T--){
        cin >> N;
        string s[N];
        for(int i = 0; i < N; i++)cin >> s[i];
        for(int c = '0'; c <= '9'; c++){
            ll ans = 0; ll a,b;
            for(int i = 0; i < N;i++){
                a = 0, b = 0;
                for(int j = 0; j < N; j++)if(s[i][j] == c){a = j; break;}
                for(int j = N-1; j >= 0; j--)if(s[i][j] == c){b = j; break;}
                ans = max(ans, (b-a)*max((ll)i,N-1-i));
            }
            for(int i = 0; i < N;i++){
                a = 0, b = 0;
                for(int j = 0; j < N; j++)if(s[j][i] == c){a = j; break;}
                for(int j = N-1; j >= 0; j--)if(s[j][i] == c){b = j; break;}
                ans = max(ans, (b-a)*max((ll)i,N-1-i));
            }
            a = 0, b = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(s[i][j] == c)b = i;
                }
            }
            for(int i = 0; i < N; i++){
                a = 0;
                for(int j = 0; j < N; j++){
                    if(s[i][j] == c)a = max({a,j,N-1-j});
                }
                ans = max(a*abs(b-i),ans);
            }
            a = 0,b =0;
            for(int i = N-1; i>=0; i--){
                for(int j = 0; j < N; j++){
                    if(s[i][j] == c)b = i;
                }
            }
            for(int i = 0; i < N; i++){
                a = 0;
                for(int j = 0; j < N; j++){
                    if(s[i][j] == c)a = max({a,j,N-1-j});
                }
                ans = max(a*abs(b-i),ans);
            }
            a = 0, b = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(s[j][i] == c)b = i;
                }
            }
            for(int i = 0; i < N; i++){
                a = 0;
                for(int j = 0; j < N; j++){
                    if(s[j][i] == c)a = max({a,j,N-1-j});
                }
                ans = max(a*abs(b-i),ans);
            }
            a = 0,b =0;
            for(int i = N-1; i>=0; i--){
                for(int j = 0; j < N; j++){
                    if(s[j][i] == c)b = i;
                }
            }
            for(int i = 0; i < N; i++){
                a = 0;
                for(int j = 0; j < N; j++){
                    if(s[j][i] == c)a = max({a,j,N-1-j});
                }
                ans = max(a*abs(b-i),ans);
            }
            cout << ans <<" ";
        }

        cout << "\n";
    }
    return 0;
}