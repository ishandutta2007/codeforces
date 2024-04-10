    #include<bits/stdc++.h>
    #define inf 1000000007
    #define f first
    #define s second
    using namespace std;
    typedef pair<int,int> ii;

    int cnt[200005], dp[200005], lst[200005];
    set<ii> s;

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n; cin >> n;
        ii ans = {0,0};

        for(int i=1; i<=n; i++){
            int u;
            cin >> u;
            cnt[u]++;
        }

        for(int i=1; i<=200000; i++)
            lst[i] = i, dp[i] = cnt[i];

        for(int i=1; i<=200000; i++){
            if( cnt[i] >= 1 ){
                if( cnt[i-1] >= 2 ) lst[i] = lst[i-1], dp[i] = dp[i-1] + cnt[i];
                if( cnt[i-1] == 1 ) lst[i] = i - 1, dp[i] = cnt[i] + 1;
            }
            ii nres = {dp[i],i};
            ans = max( ans , nres );
        }

        cout << ans.f << '\n';
        for(int i=lst[ans.s]; i<=ans.s; i++)
            cout << i << ' ';
        for(int i=ans.s; i>=lst[ans.s]; i--){
            for(int j=2; j<=cnt[i]; j++)
                cout << i << ' ';
        }

        return 0;
    }