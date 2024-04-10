// Hydro submission #61f6093e8c1511038a91e94b@1643600098175
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAXN 200020
#define pb push_back
#define rep(i, a, x) for(i = a ; i <= x ; ++ i)

using namespace std ;
struct Data{
    int num ,val ;
} base1[MAXN], base2[MAXN] ; int N, M, p, v, v1, v2, c ;
long long Ans ; int tot1, tot2, t1, t2, i ; vector <int> ans ;

inline bool Comp(Data a, Data b){ return a.val > b.val ; }
int main(){
    cin >> N >> M ; 
    memset(base1, -63, sizeof(base1)) ; 
    memset(base2, -63, sizeof(base2)) ; 
    for (i = 1 ; i <= N ; ++ i){
        scanf("%d%d", &p, &v) ;
        if (p > 1) base2[++ tot2].val = v, base2[tot2].num = i ;
        else/*qwq*/base1[++ tot1].val = v, base1[tot1].num = i ;
    }
    sort(base1 + 1, base1 + tot1 + 1, Comp), 
    sort(base2 + 1, base2 + tot2 + 1, Comp) ;
    // for (i = 1 ; i <= N ; ++ i) cout << base1[i].num << " " << base1[i].val << " qwwq " ;
    // for (i = 1 ; i <= N ; ++ i) cout << base2[i].num << " " << base2[i].val << " qwwq " ;
    if (M & 1) ans.pb(base1[1].num), Ans += base1[1].val, ++ t1, M -- ;
    while (M > 1){//>1v=2
        v2 = base2[t2 + 1].val ;
        if (t1 >= tot1 && t2 >= tot2) break ;
        v1 = base1[t1 + 1].val + base1[t1 + 2].val ; 
        if (t1 + 2 > tot1) v1 = base1[t1 + 1].val, c = 1 ; else c = 2 ; 
        if (v1 >= v2){
            Ans += v1 ; M -= c ;
            rep(i, 1, c) ans.pb(base1[++ t1].num) ; 
        }
        else Ans += v2, M -= 2, ans.pb(base2[++ t2].num) ; 
    }//whileM>1,
    if (M && t1 < tot1) Ans += base1[++ t1].val, ans.pb(base1[t1].num) ; if (Ans < 0) return puts("0\n"), 0 ; 
    cout << Ans << endl ; for (vector<int> :: iterator k = ans.begin() ; k != ans.end() ; ++ k) cout << *k << " " ;
}