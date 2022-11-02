// @author kelvin
// #includes {{{
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
int RI() { return 0; }
template<typename... T>
int RI(int& head,T&... tail) {
    return scanf("%d",&head) + RI(tail...);
}
void PRI(int x) {
    printf("%d\n",x);
}
template<typename... Args>
void PRI(int head,Args... tail) {
    printf("%d ",head);
    PRI(tail...);
}
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
#define DPRF(x) fprintf(stderr,"<"#x"=%lf>\n",x)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXK 22
#define MAXN (1<<MAXK)
#define MAXV (MAXN*2)

int k,n,vn,mask;
int s[MAXN];
bool vis[MAXV];

inline int vo(int x) {
    return x;
}

inline int va(int x) {
    return (1<<k)+x;
}

inline int hob(int x) {
    return (x&-x);
}

void init() {
    vn = 1<<(k+1);
    mask = (1<<k)-1;
    for (int v=0; v<=mask; v++)
        vis[v] = true;
    for (int v=mask+1; v<vn; v++)
        vis[v] = false;
    for (int i=0; i<n; i++)
        vis[vo(s[i])] = false;
}

void dfs_o(int);
void dfs_a(int);

void dfs_o(int v) {
    vis[vo(v)] = true;
    int u = v^mask;
    if (!vis[va(u)]) dfs_a(u);
}

void dfs_a(int b) {
    int u, h;
    vis[va(b)] = true;
    // dec bit
    int x = b;
    while(x) {
        h = hob(x);
        u = b-h;
        if (!vis[va(u)]) dfs_a(u);
        x -= h;
    }
    // back to orig
    u = b;
    if (!vis[vo(u)]) dfs_o(u);
}

int solve() {
    int sol = 0;
    init();
    for (int i=0; i<n; i++) {
       int v = vo(s[i]);
       if (!vis[v]) {
           dfs_o(v);
           sol++;
       }
    }
    return sol;
}

int main(void)
{
    RI(k,n);
    for (int i=0; i<n; i++)
        RI(s[i]);
    PRI(solve());
    return 0;
}

// vim: set fdm=marker:commentstring=//\ %s:nowrap:autoread