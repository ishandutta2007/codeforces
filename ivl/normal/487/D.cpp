#include <cstdio>

using namespace std;

int abs(int a){if (a < 0) return -a; return a;}

int n, m, q;

class row{
      public:
      int pt[10];
      row(){for (int i = 0; i < 10; ++i) pt[i] = -1;}
      
};
row runit;
row merge(row a, row b){
    row r;
    for (int i = 0; i < 10; ++i){
        if (b.pt[i] == -1 || abs(b.pt[i]) > 500) r.pt[i] = b.pt[i];
        else r.pt[i] = a.pt[b.pt[i]];
    }
    return r;
}

char mat[1 << 17][10];

int gr[15]; int un(int a){if (a == -1) return -1; if (gr[a] == a) return a; return gr[a] = un(gr[a]);}
void att(int a, int b){ // a -> b
     if (un(a) == un(b)){
        if (un(a) >= 0) gr[un(a)] = -1;
        if (un(b) >= 0) gr[un(b)] = -1;
        return;
     }
     gr[un(a)] = b;
}
row gen(char *s, int pos){
    if (s[0] == '\0') return runit;
    row r; for (int i = 0; i < m; ++i) gr[i] = i;
    for (int i = 0; i < m; ++i){
        if (s[i] == '^') r.pt[i] = i;
        if (s[i] == '<'){
           if (i == 0){r.pt[i] = -pos - 1000; continue;}
           att(i, i - 1);
        }
        if (s[i] == '>'){
           if (i == m - 1){r.pt[i] = pos + 1000; continue;}
           att(i, i + 1);
        }
    }
    for (int i = 0; i < m; ++i){
        int x = un(i);
        if (x == -1) r.pt[i] = -1;
        else r.pt[i] = r.pt[x];
    }
    return r;
}

row tur[1 << 18];
int slo, shi, scp; char sv;
void set(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > slo || hi < slo) return;
     if (lo == hi){
        mat[lo][scp] = sv;
        tur[id] = gen(mat[lo], lo);
        return;
     }
     set(id * 2, lo, (lo + hi) / 2);
     set(id * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[id] = merge(tur[id * 2], tur[id * 2 + 1]);
}
row ask(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
    if (lo > shi || hi < slo) return runit;
    if (lo >= slo && hi <= shi) return tur[id];
    return merge(ask(id * 2, lo, (lo + hi) / 2), ask(id * 2 + 1, (lo + hi + 1) / 2, hi));
}

void init(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo == hi){tur[id] = gen(mat[lo], lo); return;}
     init(id * 2, lo, (lo + hi) / 2);
     init(id * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[id] = merge(tur[id * 2], tur[id * 2 + 1]);
}

char in[100];

int main(){
    for (int i = 0; i < 10; ++i) runit.pt[i] = i;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i){
        scanf("%s", mat[i]);
    }
    init();
    for (int i = 0; i < q; ++i){
        scanf("%s", in);
        if (in[0] == 'A'){
           int x, y;
           scanf("%d%d", &x, &y); --x; --y;
           slo = 0; shi = x; row r = ask(); int T = r.pt[y];
           if (T == -1){printf("-1 -1\n"); continue;}
           if (T < -500){
              printf("%d 0\n", (-T - 1000) + 1);
              continue;
           }
           if (T > 500){
              printf("%d %d\n", T - 1000 + 1, m + 1);
              continue;
           }
           printf("0 %d\n", T + 1);
        }
        if (in[0] == 'C'){
           int x, y; char c;
           scanf("%d%d", &x, &y); scanf("%s", in); c = in[0]; --x; --y;
           slo = shi = x; scp = y; sv = c;
           set();
        }
    }
    return 0;
}