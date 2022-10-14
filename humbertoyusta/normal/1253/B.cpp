#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
#define maxn 200010
using namespace std;
typedef pair<int,int> ii;

int n, a[maxn];
set<int> s, mk;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( a[i] > 0 ){
            if( s.count(a[i]) == 1 || mk.count(a[i]) == 1 ){ cout << -1; return 0; }
            mk.insert(a[i]);
            s.insert(a[i]);
        }
        else{
            a[i] = -a[i];
            if( s.count(a[i]) == 0 ){ cout << -1; return 0; }
            s.erase(a[i]);
        }
        cnt++;
        if( s.size() == 0 ){
            ans.push_back(cnt);
            mk.clear();
            cnt = 0;
        }
    }

    if( s.size() != 0 ){ cout << -1; return 0; }

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }

    return 0;
}