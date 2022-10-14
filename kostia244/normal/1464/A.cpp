#include<bits/stdc++.h>
using namespace std;
#define I cin
#define O cout
#define V vector
#define S set
#define P pair
#define L long long
#define vo void
#define E '\n'
#define su struct
#define re return
#define W(x, y) while(x) {y}
#define F(x, y, z, t) for(x; y; z) {t}
 
su D{V<L> a;D(L n):a(n,-1){}
L p(L x) {return a[x]<0?x:a[x]=p(a[x]);}
L j(L c,L b) {c=p(c),b=p(b);if(c==b) re 0; a[c]=b; re 1;}
};
int main() {
L t,n,m,x,y,a;I>>t;W(I>>n>>m, a=0; D d(++n); W(m--,I>>x>>y;a+=x!=y?2-d.j(x,y):0;) O<<a<<E;)
}