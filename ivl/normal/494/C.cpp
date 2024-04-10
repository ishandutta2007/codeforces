#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define x first
#define y second

using namespace std;

int n, q;
int a[100005];

class klasa{
      public:
      int lo, hi;
      double p;
      vector < klasa > ch;
      klasa *par;
      klasa(int a = 0, int b = 0, double c = 0){lo = a; hi = b; p = c;}
} root;

class prob{
      public:
      vector < pair < int, double > > S; // vjerojatnost da je max <= X
      prob(){S.push_back(make_pair(-1, 0.0));}
      prob operator+(prob a){ // merge podstabla
           prob r;
           if (S.size() == 1) return a;
           if (a.S.size() == 1) return *this;
           for (vector < pair < int, double > >::iterator it = S.begin(); it != S.end(); ++it){
               vector < pair < int, double > >::iterator it2 = lower_bound(a.S.begin(), a.S.end(), make_pair(it->x, 2.0));
               if (it2 == a.S.begin()) continue;
               --it2;
               if (it2->x == -1) continue; // -> it->x != -1
               if (it2->x == it->x){
                  r.S.push_back(make_pair(it->x, it->y * it2->y));
               }
               else {
                    r.S.push_back(make_pair(it->x, it->y * it2->y));
               }
           }
           for (vector < pair < int, double > >::iterator it = a.S.begin(); it != a.S.end(); ++it){
               vector < pair < int, double > >::iterator it2 = lower_bound(S.begin(), S.end(), make_pair(it->x, 2.0));
               if (it2 == S.begin()) continue;
               --it2;
               if (it2->x == -1) continue; // -> it->x != -1
               if (it2->x == it->x){
                  continue;
               }
               else {
                    r.S.push_back(make_pair(it->x, it->y * it2->y));
               }
           }
           sort(r.S.begin(), r.S.end());
           return r;
      }
};
prob gu(int x){
     prob r;
     r.S.push_back(make_pair(a[x], 1.0));
     return r;
}
prob grow(prob a, double p){
     prob r;
     static vector < pair < int, double > > V; V.clear();
     for (vector < pair < int, double > >::iterator it = a.S.begin(); it != a.S.end(); ++it){
         if (it->x == -1) continue;
         double pp = it->y;
         --it; pp -= it->y; ++it;
         V.push_back(make_pair(it->x, pp * (1 - p)));
         V.push_back(make_pair(it->x + 1, pp * p));
     }
     sort(V.begin(), V.end());
     double d = 0;
     for (int i = 0, j = 0; i < V.size(); i = j){
         while (j < V.size() && V[j].x == V[i].x) ++j;
         for (int k = i; k < j; ++k) d += V[k].y;
         r.S.push_back(make_pair(V[i].x, d));
     }
     return r;
}

prob dfs(klasa *curr){
     prob r; //printf("%d %d(%d)\n", curr->lo, curr->hi, curr->ch.size());
     if (curr->ch.size() == 0){
        for (int i = curr->lo; i <= curr->hi; ++i) r = (r + gu(i));
        //printf(" --- %d\n", r.S.size());
        return grow(r, curr->p);
     }
     for (int i = curr->lo; i < curr->ch[0].lo; ++i) r = (r + gu(i));
     for (int i = curr->ch.back().hi + 1; i <= curr->hi; ++i) r = (r + gu(i));
     for (int i = 0; i < curr->ch.size(); ++i){
         r = (r + dfs(&(curr->ch[i])));
     }
     for (int i = 1; i < curr->ch.size(); ++i){
         for (int j = curr->ch[i - 1].hi + 1; j < curr->ch[i].lo; ++j) r = (r + gu(j));
     }
     return grow(r, curr->p);
}

bool cmp(pair < pair < int, int >, double > a, pair < pair < int, int >, double > b){
     if (a.x.x != b.x.x) return a.x.x < b.x.x;
     return a.x.y > b.x.y;
}

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    vector < pair < pair < int, int >, double > > V;
    for (int i = 0; i < q; ++i){
        int a, b; double c; scanf("%d%d%lf", &a, &b, &c);
        V.push_back(make_pair(make_pair(a, b), c));
    }
    sort(V.begin(), V.end(), cmp);
    klasa *curr;
    curr = &root;
    root.lo = 1; root.hi = n; root.p = 0;
    for (int i = 0; i < q; ++i){ // gradnja stabla
        while (curr->hi < V[i].x.x) curr = curr->par; // dizi dok god su disjunktni
        curr->ch.push_back(klasa(V[i].x.x, V[i].x.y, V[i].y));
        curr->ch.back().par = curr;
        curr = &(curr->ch.back());
    }
    prob P = dfs(&root);
    ////////////////////////////////////////
    //P = gu(1);
    //P = grow(P, 0.5);
    ////////////////////////////////////////
    double exp = 0, prev = 0;
    for (vector < pair < int, double > >::iterator it = P.S.begin(); it != P.S.end(); ++it){
        //printf("%d %lf\n", it->x, it->y);
        exp += it->x * (it->y - prev);
        prev = it->y;
    }
    printf("%.9lf\n", exp);
    return 0;
}