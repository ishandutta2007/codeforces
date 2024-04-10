#include<bits/stdc++.h>
#define maxn 100005
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;

int u,n;
set<int> s;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> u;
        if(u!=0) s.insert(u);
    }

    cout << s.size() << '\n';

return 0;
}