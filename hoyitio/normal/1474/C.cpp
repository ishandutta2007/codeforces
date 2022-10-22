#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e3 + 5;
int a[maxn];
int n;
#define P pair<int,int>
vector<P> ans;
map<int,int> s;
bool check(int x){
    ans.clear();
    s.clear();
    fors(i,1,n+1) s[a[i]]++;
    for(int i = 0; i < n/2; ++i){
        int mx = (*s.rbegin()).first;
        int ned = x-mx;
        //cout<<"mx:"<<mx<<" ned:"<<ned<<endl;
        if(s[mx] == 0) return false;
        s[mx]--; if(s[mx] == 0) s.erase(mx);
        if(s[ned] == 0) return false;
        s[ned]--; if(s[ned] == 0) s.erase(ned);
        x = mx;
        ans.pb(P(mx, ned));
    }return true;
}
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%d", &n); n*=2;
        fors(i,1,n+1) scanf("%d", &a[i]);
        sort(a+1,a+1+n);
        int ok = 0;
        int x;
        //check(8);
        fors(i,1,n) if(check(a[i]+a[n])){ok = 1; x = a[i] + a[n];break;}
        if(ok) puts("YES");
        else {
            puts("NO");continue;
        }
        printf("%d\n", x);
        fors(i,0,ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);

    }
	return 0;
}