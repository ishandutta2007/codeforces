//if(abs(arry1[i].first - arry2[j].first) > 1 )res += arry2[j].first - arry1[i].first ;
#include<bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
const ll inf = 1e18,mod = 1e9+7,maxn = 1e5+10;
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main(){
    fast_io;
    int t;cin >> t;
    for(int k = 0 ; k < t ; k++){
        int n,x;cin >> n >> x;
        ll com = - inf;
        ll biggest_shot = -inf;
        ll biggest_comp_att=-inf;
        ll biggest_comp_heal = inf;
        for(int i = 0 ; i < n ; i++){
            int a,h;cin >> a >> h;
            int c = a-h;
            if(a > biggest_shot)biggest_shot  =a;
            if(c > biggest_comp_att - biggest_comp_heal){
                biggest_comp_att = a;
                biggest_comp_heal = h;
            }
            else if(c == biggest_comp_att - biggest_comp_heal){
                if(a > biggest_comp_att){
                    biggest_comp_att  =a;
                    biggest_comp_heal = h;
                }
            }
        }
        int mov= biggest_comp_att - biggest_comp_heal;
        int maxy = biggest_shot;
        if(mov <= 0 && x-maxy > 0)cout << -1 << endl;
        else{
            int ans = 1;
            x-=maxy;
            if(x <= 0)cout << ans << endl;
            else{
                if(x%mov == 0)ans += x/mov;
                else ans += (x/mov)+1;
                cout << ans << endl;
            }
        }




    }
    return 0;
}