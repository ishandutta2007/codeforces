#include<bits/stdc++.h>
#define MAX   100100
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int a[MAX];
int n,q;
int gcdLog[MAX][LOG+1];
int lg2[MAX];
vector<ii> v;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        v.push_back(ii(a[i],i));
    }
    sort(v.begin(),v.end());
}
inline int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
void precount(void) {
    FOR(i,1,n) gcdLog[i][0]=a[i];
    FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1) gcdLog[i][j]=gcd(gcdLog[i][j-1],gcdLog[i+MASK(j-1)][j-1]);
    FOR(i,1,n) {
        while (MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
}
inline int getGCD(int l,int r) {
    int k=lg2[r-l+1];
    return (gcd(gcdLog[l][k],gcdLog[r-MASK(k)+1][k]));
}
inline int countVal(int l,int r,int val) {
    int L=lower_bound(v.begin(),v.end(),ii(val,l))-v.begin();
    int R=upper_bound(v.begin(),v.end(),ii(val,r))-v.begin();
    if (R>L) return (R-L); else return (0);
}
int query(int l,int r) {
    return (r-l+1-countVal(l,r,getGCD(l,r)));
}
void process(void) {
    scanf("%d",&q);
    REP(zz,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
}
int main(void) {
    init();
    precount();
    process();
    return 0;
}