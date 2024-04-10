#include <bits/stdc++.h>
#define va first
#define vb second
#define lb lower_bound
#define pb push_back
#define all(v) v.begin(),v.end()
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using lf = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int mx = 1e5 + 5;
string S[mx], tmp;
int key[mx];

unordered_map<int,vector<int>> M;
vector<vector<int>> res;
int n;

struct node{
    int nxt[26];
    int acc;
    node():acc(-1){}
} tr[1000005];
int ptr;

int main(){
    fio;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> S[i] >> tmp;
        int &k = key[i];
        for(int j = 0; j < S[i].size(); j++) S[i][j] -= 'a';
        for(char c : tmp){
            k |= (1 << c - 'a');
        }
        M[k].push_back(i);
    }
    for(auto a : M){
        for(int i : a.vb){
            while(S[i].size() && (a.va >> S[i].back()) & 1 ) S[i].pop_back();
        }
        int rt = ++ptr;
        for(int i : a.vb){
            int now = rt;
            for(int j = 0; j < S[i].size(); j++){
                if(tr[now].nxt[ S[i][j] ]){
                    now = tr[now].nxt[ S[i][j] ];
                }
                else{
                    now = (tr[now].nxt[ S[i][j] ] = ++ptr);
                }
            }
            if(tr[now].acc == -1){
                tr[now].acc = res.size();
                res.push_back(vector<int>());
                res.back().push_back(i);
            }else{
                res[ tr[now].acc ].push_back(i);
            }
        }
    }
    cout << res.size() << '\n';
    for(auto &v : res){
        cout << v.size() << ' ';
        for(int u : v) cout << u << ' ';
        cout << '\n';
    }
}