/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int b[maxN];
int ans = oo;
int m = 0;

void cop(){
    for1(i, 0, m - 1) b[i] = a[i];
}

int transfer(int num, int targ){
    bool maf = 0;
    if(num == 0 && targ == 1){
        maf = 1;
    }
    int cur = -1;
    for1(i, targ, m - 1){
        if(b[i] == num){
            cur = i;
            break;
        }
    }
    if(cur == -1) return oo;
    int rs = 0;
    bool killed = 1;
    while(cur != targ){
        if((cur != m - 1) || (b[cur - 1])){
            swap(b[cur], b[cur - 1]); ++rs;
            --cur;
        }
        else{

            int fk = -1;
            for2(i, m - 2, 0){
                if(b[i] != 0){
                    fk = i; break;
                }
            }
            if(fk < targ) return oo;
            swap(b[cur], b[fk]);
            rs += ((cur - fk) * 2 - 1);
            cur = fk;
        }
    }
    return rs;
}



void func(int g1, int g2){
    cop();
    int dumb = transfer(g1, 0) + transfer(g2, 1);
    ans = min(ans, dumb);
    // cout << dumb << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n){
        a[m++] = n % 10;
        n /= 10;
    }
    func(0, 0);
    func(0, 5);
    func(5, 2);
    func(5, 7);
    if(ans > mod) cout << -1 << endl;
    else cout << ans << endl;
}