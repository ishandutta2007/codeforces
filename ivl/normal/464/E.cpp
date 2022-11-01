#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= Mod;
        x = (int)y;
    }
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= Mod) a.x -= Mod; return a;}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}

mint Pot = 43;
mint PotP[200005];
mint SumSeq[200005];

const int offset = (1<<17);

class Node{
public:
    class Val{
    public:
        int Len;
        mint V;
        Val operator+(Val b){
            return {Len + b.Len, V * PotP[b.Len] + b.V};
        }
    } V;
    Node *l, *r;
} *Dummy, *Dummy2;
typedef Node* Tur;
void TurnamentInit(){
    Dummy = new Node;
    Dummy->l = Dummy->r = Dummy;
    Dummy2 = new Node;
    Dummy2->l = Dummy2->r = Dummy2;
}
Node::Val Value(Tur T, int lo, int hi){
    if (T == Dummy) return {hi - lo + 1, 0};
    if (T == Dummy2) return {hi - lo + 1, SumSeq[hi - lo + 1]};
    return T->V;
}
Tur Set(Tur Curr, int lo, int hi, int slo, int shi, char v){
    if (lo > shi || hi < slo) return Curr;
    if (lo >= slo && hi <= shi){
        if (v == 0) return Dummy;
        else return Dummy2;
    }
    Tur T = new Node;
    int m = (lo + hi) / 2;
    T->l = Set(Curr->l, lo, m, slo, shi, v);
    T->r = Set(Curr->r, m + 1, hi, slo, shi, v);
    T->V = Value(T->l, lo, m) + Value(T->r, m + 1, hi);

    return T;
}
Tur Set(Tur T, int lo, int hi, char v){return Set(T, 0, offset - 1, lo, hi, v);}
Node::Val Query(Tur Curr, int lo, int hi, int slo, int shi){
    if (lo > shi || hi < slo) return {0, 0};
    if (Curr == Dummy || Curr == Dummy2){
        slo = max(slo, lo), shi = min(shi, hi);
        if (Curr == Dummy) return {shi - slo + 1, 0};
        else return {shi - slo + 1, SumSeq[shi - slo + 1]};
    }
    if (lo >= slo && hi <= shi) return Value(Curr, lo, hi);
    int m = (lo + hi) / 2;
    return Query(Curr->l, lo, m, slo, shi) + Query(Curr->r, m + 1, hi, slo, shi);
}
Node::Val Query(Tur T, int lo, int hi){return Query(T, 0, offset - 1, lo, hi);}

int BinaryUpper(Tur T, int lower){
    int lo = lower - 1, hi = offset - 1, mid = (lo + hi + 1) / 2;
    while (lo != hi){
        if (Query(T, lower, mid).V.x == SumSeq[mid - lower + 1].x) lo = mid;
        else hi = mid - 1;
        mid = (lo + hi + 1) / 2;
    } return lo;
}

pair < int, bool > BinaryUpper2(Tur T, int lo, int hi, int x){
    if (hi < x) return {0, true};
    int m = (lo + hi) / 2;
    pair < int, bool > R;
    if (lo >= x){
        if (Value(T, lo, hi).V.x == SumSeq[hi - lo + 1].x) return {hi - lo + 1, true};
        if (lo == hi) return {0, false};
        R = BinaryUpper2(T->l, lo, m, x);
        if (!R.y) return R;
        R = BinaryUpper2(T->r, m + 1, hi, x);
        R.x += m - lo + 1;
        return R;
    }
    R = BinaryUpper2(T->l, lo, m, x);
    if (!R.y) return R;
    auto R2 = BinaryUpper2(T->r, m + 1, hi, x);
    R2.x += R.x;
    return R2;
}

Tur Add(Tur T, int x){
    int y = BinaryUpper2(T, 0, offset - 1, x).x + x - 1;
    if (y >= x) T = Set(T, x, y, 0);
    return Set(T, y + 1, y + 1, 1);
}

Tur oo;

int n, m;
vector < pii > E[100005];
int s, t;

bool ConCheckDFS(int id){
    static bool bio[100005];
    if (bio[id]++) return false;
    if (id == t) return true;
    for (auto x : E[id]) if (ConCheckDFS(x.x)) return true;
    return false;
}

void Display(Tur T){
    REP(offset,i) printf("%d ", Query(T, i, i).V.x);
    printf("\n");
}

int LCS(Tur A, Tur B, int lo, int hi){
    if (Value(A, lo, hi).V.x == Value(B, lo, hi).V.x) return lo;
    if (lo == hi) return lo + 1;
    int m = (lo + hi) / 2;
    if (Value(A->r, m+1, hi).V.x != Value(B->r, m+1, hi).V.x) return LCS(A->r, B->r, m+1, hi);
    else return LCS(A->l, B->l, lo, m);
}

int _MID;
bool Cmp(Tur A, Tur B){
    _MID = LCS(A, B, 0, offset - 1);
    if (_MID == 0) return false;
    return Query(A, _MID - 1, _MID - 1).V.x < Query(B, _MID - 1, _MID - 1).V.x;
}
bool CmpBig(pair < Tur, int > A, pair < Tur, int > B){
    bool tt = Cmp(A.x, B.x);
    if (_MID) return tt;
    return A.y < B.y;
}
class SetCmp{
public:
    bool operator()(pair < Tur, int > A, pair < Tur, int > B){return CmpBig(A, B);}
};

Tur Dist[100005];

int main(){
    PotP[0] = 1;
    REP(200000,i) PotP[i+1] = PotP[i] * Pot;
    SumSeq[0] = 0;
    REP(200000,i) SumSeq[i+1] = SumSeq[i] + PotP[i];
    TurnamentInit();
    oo = Set(Dummy, 0, offset - 1, 1);

    scanf("%d%d", &n, &m);
    REP(m,i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[a].pb({b, c});
        E[b].pb({a, c});
    } scanf("%d%d", &s, &t);

    if (!ConCheckDFS(s)){printf("-1\n"); return 0;}

    REP(n+1,i) Dist[i] = oo;
    Dist[s] = Dummy;
    vector < int > Back(n+1, -1);
    set < pair < Tur, int >, SetCmp > S;
    S.insert({Dist[s], s});
    while (!S.empty()){
        int id = S.begin()->y;
        S.erase(S.begin());
        for (auto x : E[id]){
            Tur T = Add(Dist[id], x.y);
            if (!Cmp(T, Dist[x.x])) continue;
            S.erase({Dist[x.x], x.x});
            Dist[x.x] = T;
            Back[x.x] = id;
            S.insert({Dist[x.x], x.x});
        }
    }
    mint R = 0;
    for (int i = offset - 1; i >= 0; --i) R = R * 2 + Query(Dist[t], i, i).V.x;
    printf("%d\n", R.x);
    vector < int > Seq = {t};
    while (Seq.back() != s) Seq.pb(Back[Seq.back()]);
    reverse(Seq.begin(), Seq.end());
    printf("%d\n", (int)Seq.size());
    for (auto x : Seq) printf("%d ", x); printf("\n");
    return 0;
}