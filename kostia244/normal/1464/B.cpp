#include<bits/stdc++.h>
using namespace std;
#define I cin
#define O cout
#define V vector
#define S set
#define ST string
#define P pair
#define L long long
#define vo void
#define E '\n'
#define su struct
#define re return
#define sz size()
#define bk back()
#define pu push_back
#define W(x, y) while(x) {y}
#define F(x, y, z, t) for(x; y; z) {t}
#define Fe(x, y, z) for(auto &x : y) {z}
ST s;
L a,x,y,p,i,z,o,j;
L _c(L z, L o, L i, L x, L y) { re (z*o*x) + i*(y-x); }
int main() {
I>>s>>x>>y;if(x>y){swap(x, y);Fe(i,s, if(i-'?')i^=1;)}
V<L> r[2],q;
p=i=z=o=0;
Fe(c, s,Fe(i, r, i.pu(i.sz?i.bk:0);) if(c!='?')
r[c-'0'].bk++;else q.pu(p);p++; if(c-'0') o++;
else (i+=o)|z++;)
#define g(t,l,R) (r[t][R] - (l?r[t][l-1]:0))
a=_c(z,o,i,x,y);
Fe(c,q, i+=g(1,0,c)-g(0,c,s.sz-1); z++;o--;a=min(a, _c(z,o,i,x,y)););
O<<a;
}