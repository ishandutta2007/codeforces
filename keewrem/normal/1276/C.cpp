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
const int MAXN = 200010;
ll T,N;
int main(){
    cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    sort(v.begin(),v.end());
    vector<pii> vv;
    int c = 0, l = 0;
    for(int x: v){
        if (l != x) {
            if(l)vv.pb({c,l});
            c = 0,l = x;
        }
        c++;
    }
    vv.pb({c,l});
    sort(vv.begin(),vv.end());
    //for(auto x: vv)cout << x.fi<<" ";
    cout << endl;
    int ind = 0, cnt = 0, ans = 0, col;
    for(int i = 1; i*i <= N; i++){
        cnt += vv.size()-ind;
        while(ind < vv.size() && vv[ind].fi == i)ind++;
        if(vv.size()>=i && i <= cnt/i)if(cnt -(cnt%i)>ans){ans = cnt - (cnt%i); col = i;}

    //    cout << "i "<<i <<" cnt "<<cnt<< endl;
    }
    cout << ans<<endl;
    int r = ans / col;
    int tab[col][r];
    ind = 0;
    reverse(vv.begin(),vv.end());
    for(auto &x: vv)x.fi = min(x.fi,col);
    for(int i = 0; i < r; i++)for(int j = 0; j < col; j++){
        if(!vv[ind].fi)ind++;
        tab[j][(i+j)%r] = vv[ind].se; vv[ind].fi--;
    }
    cout << col << " "<<r<<endl;
    for(int i = 0; i < col; i++)for(int j = 0; j < r; j++){
        cout << tab[i][j] << " \n"[j == r-1];
    }
    return 0;
}