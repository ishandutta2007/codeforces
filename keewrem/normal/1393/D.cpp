#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1000000007;

// FENWICK

int fenwick[MAXN];
void update(int pos, int delta){
    for(;pos < MAXN; pos+=pos&-pos)fenwick[pos]+=delta;
}
int query(int pos){
    int res = 0;
    for(; pos>0; pos-=pos&-pos)res+=fenwick[pos];
    return res;
}

// DSU

int uf[MAXN], rnk[MAXN];

int find(int a){
    if(uf[a]!=a)uf[a]=find(uf[a]);
    return uf[a];
}

void dsunion(int a, int b){
    a = find(a); b = find(b);
    if(rnk[a]<rnk[b])swap(a,b);
    rnk[a]=max(rnk[a],rnk[b]+1);
    uf[b]=a;
}

// FASTEXP

ll fexp(ll b, int e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN];
ll bin (ll a, ll b){
    return (((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
}

int N,M;
bool ck(int a, int b){
    return !(a >= 0 && a < N && b < M && b >= 0);
}
pii dir[4]={{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    cin >> N >> M;
    ll ans = 0;
    int cnt[N][M];
    string kek[N];
    for(int i = 0; i < N; i++){
        cin >> kek[i];
    }
    int x,y;
    vector<pii> q;
    bool tkn[N][M];
    int left = N*M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cnt[i][j] = 0;
            for(int k = 0; k < 4; k++){
                x = i + dir[k].fi;
                y = j + dir[k].se;
                if(ck(x,y))continue;
                if(kek[x][y]==kek[i][j])cnt[i][j]++;
            }
            tkn [i][j] = 0;
            if(cnt[i][j]<4){
                tkn[i][j]=1;
                q.pb({i,j});
            }

        }
    }
    int a,b;

    vector<pii> temp;
    while(left > 0){
        ans += left;
        for(auto lwl: q){
            a = lwl.fi;
            b = lwl.se;
            left--;
            for(int k = 0; k < 4; k++){
                x = a + dir[k].fi;
                y = b + dir[k].se;
                if(ck(x,y))continue;
                if(!tkn[x][y]){
                    temp.pb({x,y});
                    tkn[x][y] = 1;
                }
            }
        }
        q.clear();
        swap(temp,q);
    }
    cout << ans;
    return 0;
}