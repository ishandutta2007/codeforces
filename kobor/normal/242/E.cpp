//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int M=1<<17;
const int B=21;

int sub[B+1][2*M+5], load[B+1][2*M+5], rozm[2*M+5];
int n, m;

ll pot(ll a, ll b){
    ll ret=1;
    FOR(i, 1, b){
        ret*=a;
    }
    return ret;
}

void add(int v, int x, int nr){
    load[nr][v]^=x;
    if(x){
        sub[nr][v]=rozm[v]-sub[nr][v];
    }
}

void push(int v, int nr){
    add(2*v, load[nr][v], nr);
    add(2*v+1, load[nr][v], nr);
    load[nr][v]=0;
}

int query(int v, int l, int r, int ll, int rr, int nr){
    if(l>rr || r<ll){
        return 0;
    }
    if(l>=ll && r<=rr){
        return sub[nr][v];
    }
    int mid=(l+r)/2;
    push(v, nr);
    return query(2*v, l, mid, ll, rr, nr)+query(2*v+1, mid+1, r, ll, rr, nr);
}

void update(int v, int l, int r, int ll, int rr, int val, int nr){
    if(l>rr || r<ll){
        return;
    }
    if(l>=ll && r<=rr){
        add(v, val, nr);
        return;
    }
    int mid=(l+r)/2;
    push(v, nr);
    update(2*v, l, mid, ll, rr, val, nr);
    update(2*v+1, mid+1, r, ll, rr, val, nr);
    sub[nr][v]=sub[nr][2*v]+sub[nr][2*v+1];
}

ll query(int a, int b){
    ll ret=0;
    FOR(j, 0, B){
        ret+=query(1, 1, M, a, b, j)*pot(2, j);
    }
    return ret;
}

void update(int a, int b, int x){
    FOR(j, 0, B){
        if(x%2){
            update(1, 1, M, a, b, 1, j);
        }
        x/=2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b, x;
    cin>>n;
    FOR(i, 1, n){
        cin>>a;
        FOR(j, 0, B){
            sub[j][i+M-1]=a%2;
            a/=2;
        }
        rozm[i+M-1]=1;
    }
    FORD(i, M-1, 1){
        FOR(j, 0, B){
            sub[j][i]=sub[j][2*i]+sub[j][2*i+1];
        }
        rozm[i]=rozm[2*i]+rozm[2*i+1];
    }
    cin>>m;
    FOR(i, 1, m){
        cin>>t;
        if(t==1){
            cin>>a>>b;
            cout<<query(a, b)<<ent;
        }
        else{
            cin>>a>>b>>x;
            update(a, b, x);
        }
    }
    return 0;
}