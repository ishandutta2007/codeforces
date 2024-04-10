#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;

int n,a[maxn],abi[maxn];
map<int,int> m1,m2;
long long ans;

void update(int id){
    for(; id > 0; id -= ( id & -id ) )
        abi[id]++;
}

int query(int id){
    int res = 0;
    for(; id <= n; id += ( id & -id ) )
        res += abi[id];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        m2[a[i]]++;
    }

    for(int i=1; i<=n; i++){
        ans += query(m2[a[i]]+1);
        m1[a[i]]++;
        m2[a[i]]--;
        update(m1[a[i]]);
    }

    cout << ans << '\n';

    return 0;
}