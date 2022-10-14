#include<bits/stdc++.h>
#define maxn 200005
using namespace std;

int tc,n,a[maxn],cnt;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while( tc-- ){

        v.clear();

        cin >> n;

        a[n+1] = -1;

        for(int i=1; i<=n; i++)
            cin >> a[i];

        sort(a+1,a+n+1);

        cnt = 0;

        for(int i=1; i<=n; i++){
            cnt++;
            if( a[i] != a[i+1] ){
                v.push_back(cnt);
                cnt = 0;
            }
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int ans = v[0];
        int act = v[0];

        for(int i=1; i<v.size(); i++){
            if( act - 1 <= 0 ) break;
            if( v[i] >= act - 1 )
                v[i] = act - 1;
            act = v[i];
            ans += act;
        }
        cout << ans << '\n';
    }

    return 0;
}