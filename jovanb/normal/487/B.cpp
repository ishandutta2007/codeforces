#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int stmin[20][100005];
int stmax[20][100005];
int lg[100005];
int niz[100005];
int dp[100005];

const int INF = 1000000000;

int getmin(int l, int r){
    int j = lg[r-l+1];
    return min(stmin[j][l], stmin[j][r-(1<<j)+1]);
}

int getmax(int l, int r){
    int j = lg[r-l+1];
    return max(stmax[j][l], stmax[j][r-(1<<j)+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, s, l;
    cin >> n >> s >> l;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=2; i<=n; i++){
        lg[i] = lg[i/2] + 1;
    }
    for(int i=1; i<=n; i++){
        stmin[0][i] = niz[i];
        stmax[0][i] = niz[i];
    }
    for(int j=1; (1<<j)<=n; j++){
        int len = (1<<j);
        for(int i=1; i+len-1<=n; i++){
            stmin[j][i] = min(stmin[j-1][i], stmin[j-1][i+len/2]);
            stmax[j][i] = max(stmax[j-1][i], stmax[j-1][i+len/2]);
        }
    }
    set <pair <int, int>> q;
    for(int i=1; i<=n; i++){
        dp[i] = INF;
        if(i-l >= 0) q.insert({dp[i-l], i-l});
        while(!q.empty()){
            pair <int, int> par = *q.begin();
            int j = par.second;
            int mx = getmax(j+1, i);
            int mn = getmin(j+1, i);
            if(mx-mn > s){
                q.erase(q.begin());
                continue;
            }
            dp[i] = par.first + 1;
            break;
        }
    }
    if(dp[n] >= INF){
        cout << -1;
        return 0;
    }
    cout << dp[n];
    return 0;
}