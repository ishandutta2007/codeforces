#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n;
int a[maxN][32];
int x, y, z, k;
 
int tmax[maxN * 4][32];
int tmin[maxN * 4][32];
 
int l[maxN * 4];
int r[maxN * 4];
int vin[33];
int vax[33];
int store[6];
int sam;
 
int home[maxN];
 
void back(int pos, int ind){
    if(pos == 5){
        vin[ind] = sam; return;
    }
    back(pos + 1, ind);
    ind += (1 << pos);
    sam -= store[pos];
    back(pos + 1, ind);
    ind -= (1 << pos);
    sam += store[pos];
}
 
void redate(int node){
    for1(i, 0, 31){
        tmax[node][i] = max(tmax[node * 2][i], tmax[node * 2 + 1][i]);
        tmin[node][i] = min(tmin[node * 2][i], tmin[node * 2 + 1][i]);
    }
}
 
void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right){
        for1(i, 0, 31){
            tmax[node][i] = a[left][i];
            tmin[node][i] = a[left][i];
        }
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2    , left   , mid);
    build(node * 2 + 1, mid + 1, right);
    redate(node);
}
 
void query(int node, int left, int right){
    if(l[node] == left && r[node] == right){
        for1(i, 0, 31){
            vin[i] = min(vin[i], tmin[node][i]);
            vax[i] = max(vax[i], tmax[node][i]);
        }
        return;
    }
    else if(left >   r[node * 2]) query(node * 2 + 1, left, right);
    else if(right <= r[node * 2]) query(node * 2    , left, right);
    else{
        query(node * 2    , left           , r[node * 2]);
        query(node * 2 + 1, l[node * 2 + 1], right      );
    }
}
 
void change(int node, int place){
    if(l[node] == r[node]){
        for1(i, 0, 31){
            tmax[node][i] = vin[i];
            tmin[node][i] = vin[i];
        }
        return;
    }
    if(place > r[node * 2]) change(node * 2 + 1, place);
    else                    change(node * 2    , place);
    redate(node);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    for1(i, 1, n){
        sam = 0;
        for1(j, 0, k - 1){
            cin >> store[j];
            sam += store[j];
            store[j] *= 2;
        }
        back(0, 0);
        for1(j, 0, 31){
            a[i][j] = vin[j];
        }
    }
    build(1, 1, n);
    int o; cin >> o; while(o--){
        cin >> x;
        if(x == 2){
            cin >> x >> y;
            fill(vin, vin + 32, oo);
            fill(vax, vax + 32, -oo);
            query(1, x, y);
            int ans = 0;
            for1(i, 0, 31){
                ans = max(ans, vax[i] - vin[i]);
            }
            cout << ans << endl;
        }
        else{
            int i; cin >> i;
            sam = 0;
            for1(j, 0, k - 1){
                cin >> store[j];
                sam += store[j];
                store[j] *= 2;
            }
            back(0, 0);
            change(1, i);
        }
    }
}