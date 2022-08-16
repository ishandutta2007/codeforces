#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define ll long long
const int N = 16;
ll fact[N];
vector<int> dp[N];  
bool cmp(vector<int> & x, vector<int> & y){
    if(x.size() > y.size()) return 1;
    if(x.size() < y.size()) return 0;
    for(int i = 0; i < x.size(); i++){
        if(x[i] > y[i]) return 1;
        else if(y[i] > x[i]) return 0;
    }
    return 0;
}
vector<int> max(vector<int> & a, vector<int> & b){
    return cmp(a, b) ? a : b;
}
ll MAX;
map<ll, int> ulta;
void pre(){
    fact[0] = 1; 
    for(int i = 1; i < N; i++){
        fact[i] = fact[i - 1] * i;
        if(i >= 2) ulta[fact[i]] = i;
    }
    MAX = fact[N - 1];
}
void dfs(ll x, int ind, vector<int> vec){
    // cerr << x << " " << ind << endl;
    if(ind == N && ulta[x]){
        reverse(vec.begin(), vec.end());
        dp[ulta[x]] = max(dp[ulta[x]], vec);
        return;
    }
    if(ind == N) return;
    ll y0 = fact[ind]; ll y = 1; 
    for(;y <= MAX / x; y = y0 * y){
        dfs(x * y, ind + 1, vec);
        vec.push_back(ind);
    }
}
int main(){
    pre();
    dfs(1, 2, {});
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> vec;
    for(int i = 0; i < s.length(); i++){
        int c = s[i] - '0';
        for(int x : dp[c]) vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for(int i = vec.size() - 1; i >= 0; i--) cout << vec[i];
}