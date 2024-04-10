#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
vector<int> ans;
int a, b;
void sol(int x, int y){
    fors(i,0,x+1){
        if(i > a) break;
        int c = a-i;
        if(c <= y) ans.pb(x-i + c);
    }
}
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%d%d", &a, &b);

        int m = a+b;
        ans.clear();
        sol(m/2,m-m/2);
        if(m&1) sol(m-m/2,m/2);
        sort(all(ans)); ans.erase(unique(all(ans)), ans.end());
        cout<<ans.size()<<endl;
        for(int x:ans) printf("%d ", x); puts("");
    }
	return 0;
}