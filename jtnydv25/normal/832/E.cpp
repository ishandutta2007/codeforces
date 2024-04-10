#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define F first
#define S second
#define ll long long
const int N = 505;
int mod = 5;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
int _inv[5] = {0, 1, 3, 2, 4};
inline int inv(int a){ return powr(a, mod - 2);}
vector<pair<int, pair<int, int> > > transforms;
vector<int> zero_rows;
int FREE = 0;
struct matrix{
    int M[N][N], n, m;
    matrix(){}
    matrix(int _n, int _m){n = _n, m = _m;}
    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cerr << M[i][j] << " ";
            cerr << endl;
        } cerr << endl;
    }
    void rre(){
        bool done[N] = {0};
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(M[i][j] && !done[i]){
                    done[i] = 1;
                    int INV = _inv[M[i][j]];
                    for(int k = i + 1; k < n; k++){
                        int p = mul(M[k][j], INV);
                        for(int _j = 0; _j < m; _j++) M[k][_j] = sub(M[k][_j], mul(p, M[i][_j]));
                        transforms.push_back({i, {k, p}});
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            bool f = 1;
            for(int j = 0; j < m; j++) if(M[i][j]) f = 0;
            if(f) zero_rows.push_back(i);
        }
    }
} ;
char str[505];
int b[N], powers[505];
int main(){
    // mod = 1e9 + 7;
    int n, m, q;
    sd(n); sd(m);
    matrix mat = matrix(m, n);
    for(int i= 0; i < n; i++){
        scanf("%s", str);
        for(int j = 0; j < m; j++){
            mat.M[j][i] = str[j] - 'a';
        }
    }
    mat.rre();
    sd(q);
    while(q--){
        scanf("%s", str);
        for(int i = 0; i < m; i++) b[i] = str[i] - 'a';
        for(auto it : transforms){
            int i = it.F, k = it.S.F, p = it.S.S;
            b[k] = sub(b[k], mul(p, b[i]));
        }
        bool f = 0;
        for(int i : zero_rows) if(b[i]) f = 1;
        if(f){
            printf("%d\n", 0);
            continue;
        }
        mod = 1e9 + 7;
        int ans = 1;
        for(int i = 0; i < n - (m - zero_rows.size()); i++) ans = mul(ans, 5);
        printf("%d\n", ans);
        mod = 5;
    }   
}