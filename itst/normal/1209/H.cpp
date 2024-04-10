#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define PDI pair < ld , int > 
const int _ = 4e5 + 3;
map < int , ld > nval; vector < int > pos; int N , L; ld ubd[_] , sum[_] , E[_]; vector < PDI > seg;

namespace segt{
    ld mn[_ << 2] , mrk[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

    void mark(int x , ld val){mn[x] += val; mrk[x] += val;}
    void down(int x){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}

    void init(int x , int l , int r){
        if(l == r) (void)(mn[x] = sum[l]);
        else{init(lch , l , mid); init(rch , mid + 1 , r); mn[x] = min(mn[lch] , mn[rch]);}
    }

    void modify(int x , int l , int r , int L , int R , ld val){
        if(l >= L && r <= R) return mark(x , val);
        down(x); if(mid >= L) modify(lch , l , mid , L , R , val);
        if(mid < R) modify(rch , mid + 1 , r , L , R , val);
        mn[x] = min(mn[lch] , mn[rch]);
    }

    ld qry(int x , int l , int r , int L , int R){
        if(l >= L && r <= R) return mn[x];
		down(x);
        ld mn = 1e18; if(mid >= L) mn = qry(lch , l , mid , L , R);
        if(mid < R) mn = min(mn , qry(rch , mid + 1 , r , L , R));
        return mn;
    }
}using namespace segt;

int main(){
    scanf("%d %d" , &N , &L);
    for(int i = 1 ; i <= N ; ++i){
        int X , Y; ld val; scanf("%d %d %Lf" , &X , &Y , &val);
        pos.push_back(X); pos.push_back(Y); nval[X] = val;
    }
    pos.push_back(0); pos.push_back(L); sort(pos.begin() , pos.end());
    pos.resize(unique(pos.begin() , pos.end()) - pos.begin());
    for(int i = 1 ; i < pos.size() ; ++i){
        ld val = nval[pos[i - 1]] + 1; seg.push_back(PDI(val , i));
        sum[i] = sum[i - 1] - (E[i] = val != 1 ? (pos[i] - pos[i - 1]) / (1.0 - val) : 0);
        ubd[i] = (pos[i] - pos[i - 1]) / (val + 1.0) - E[i];
    }
    segt::init(1 , 1 , seg.size()); sort(seg.begin() , seg.end());
    for(auto t : seg){
        int id = t.second; ld mn = min(ubd[id] , segt::qry(1 , 1 , seg.size() , id , seg.size()));
        E[id] += mn; segt::modify(1 , 1 , seg.size() , id , seg.size() , -mn);
    }
    ld ans = 0;
    for(int i = 1 ; i < pos.size() ; ++i) ans += (pos[i] - pos[i - 1] - E[i]) / (nval[pos[i - 1]] + 1);
    cout << fixed << setprecision(11) << ans; return 0;
}