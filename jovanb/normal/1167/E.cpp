#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

/*ll cnt;
unordered_map <ll, ll> u;*/

ll niz[2000005];
ll first[2000005];
ll last[2000005];
ll mn[2000005];
ll mx[2000005];
//vector <ll> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, x;
    cin >> n >> x;
    for(ll i=1; i<=n; i++){
        cin >> niz[i];
        //vec.push_back(niz[i]);
    }
    /*sort(vec.begin(), vec.end());
    for(auto c : vec){
        if(!u[c]) u[c] = ++cnt;
    }
    x = cnt;*/
    for(ll i=1; i<=n; i++){
        //niz[i] = u[niz[i]];
        if(!first[niz[i]]) first[niz[i]] = i;
        last[niz[i]] = i;
    }
    for(ll i=0; i<=x; i++){
        if(first[i] == 0){
            first[i] = n+1;
            last[i] = 0;
        }
    }
    ll maxpref = 1;
    mx[1] = last[1];
    while(maxpref < x){
        if(first[maxpref+1] > mx[maxpref] || first[maxpref+1] == 0) maxpref++;
        else break;
        mx[maxpref] = max(mx[maxpref-1], last[maxpref]);
    }
    mn[x] = first[x];
    ll maxsuf = x;
    while(maxsuf > 1){
        if(last[maxsuf-1] < mn[maxsuf] || last[maxsuf-1] == 0) maxsuf--;
        else break;
        mn[maxsuf] = min(mn[maxsuf+1], first[maxsuf]);
    }
    if(maxpref == x){
        cout << (1LL*x*(x+1))/2;
        return 0;
    }
    ll sum = 0;
    for(ll i=1; i<=x; i++){
        ///[i, j] moze;
        if(i-1 > maxpref) break;
        ll l = max(maxsuf-1, i), r = x, j = x;
        while(l <= r){
            ll mid = (l+r)/2;
            //cout << mid << " " << i << endl;
            if(mn[mid+1] > mx[i-1] && mid+1 >= maxsuf){
                r = mid-1;
                j = mid;
            }
            else l = mid+1;
        }
        //if(res == 0) continue;
        //cout << j << endl << endl;
        sum += x-j+1;
        //cout << sum << endl;
    }
    cout << sum;
    return 0;
}