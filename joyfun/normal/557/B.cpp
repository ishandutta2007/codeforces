#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define de(x) cout << #x << "=" << x << endl

const int N=200005;
int a[N];

int main() {
    int n,w;scanf("%d%d",&n,&w);
    for(int i=1;i<=2*n;++i) {
        scanf("%d",a+i);
    }
    sort(a+1,a+1+2*n);
    double ans=fmin(fmin(a[1],a[n+1]*1.0/2),w*1.0/3/n);
    printf("%.10f\n", ans*3*n);
    return 0;
}