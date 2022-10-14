    /// Code by humbertoyusta
    #include<bits/stdc++.h>
    using namespace std;
    // Pragma
    #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
    // Macros:
    #define f first
    #define s second
    typedef long long ll;
    // debugging macros
    #define db(x) cerr << #x << ": " << (x) << '\n';
    #define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
    #define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
    // Constraints:
    const int maxn = 1010;
    const int mod = 1000000007;
    const int mod2 = 998244353;
    const double eps = 1e-9;
    // Quick Functions------------------------------------------
    int qpow(int b,int e){
        if( !e ) return 1;
        if( e & 1 ) return qpow(b,e-1) * b % mod;
        int pwur = qpow(b,e>>1);
        return pwur * pwur % mod;
    }
    mt19937_64 rnd(time(0));
    ll rng (ll a, ll b){
        return uniform_int_distribution<ll>(a,b)(rnd);
    }
    // Problem starts here -------------------------------------



    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout.setf(ios::fixed); cout.precision(10);

        //freopen("a.in","r",stdin);
        //freopen("a.in","w",stdout);

        int tc;
        cin >> tc;
        while( tc-- ){

            int n, m;
            cin >> n >> m;

            vector<pair<ll,pair<ll,ll>>> events;

            vector<ll> a(n);
            map<ll,ll> mp;
            for(int i=0; i<n; i++){
                cin >> a[i];
                mp[a[i]] = 1;
                events.push_back({a[i],{0,i}});
            }
            sort(a.begin(),a.end());

            vector<pair<ll,ll>> b(m);
            vector<bool> bad(m);

            for(int i=0; i<m; i++){
                cin >> b[i].f >> b[i].s;
                events.push_back({b[i].f,{-1,i}});
                events.push_back({b[i].s,{1,i}});
                if( mp[b[i].f] || mp[b[i].s] )
                    bad[i] = 1;
            }

            vector<pair<ll,ll>> belong(m);
            int curr = 0;

            sort(events.begin(),events.end());
            for( auto i : events ){
                if( i.s.f == 0 ){
                    curr ++;
                }
                if( i.s.f == -1 ){
                    belong[i.s.s].f = curr;
                }
                if( i.s.f == 1 ){
                    belong [i.s.s].s = curr;
                }
            }

            vector<pair<ll,ll>> seg[n+1];
            for(int i=0; i<m; i++){
                if( belong[i].f != belong[i].s || bad[i] ) continue;
                seg[belong[i].f].push_back(b[i]);
            }

            vector<ll> cons = { 1ll * mod * mod , 1ll * mod * mod };
            vector<vector<ll>> dp(n+1,cons);
            ll d = 0;
            for( auto i : seg[0] ){
                d = max( d , (ll)a[0] - i.s );
            }
            assert(d >= 0);
            dp[0][0] = d;
            dp[0][1] = d + d;

            for(int i=1; i<n; i++){
                sort(seg[i].begin(),seg[i].end());

                if( seg[i].size() == 0 ){
                    dp[i][1] = dp[i][0] = dp[i-1][0];
                    continue;
                }

                // taking all by r
                ll d = 0;
                for( auto j : seg[i] )
                    d = max( d , a[i] - j.s );
                assert(d >= 0 );

                dp[i][0] = min( dp[i][0] , dp[i-1][0] + d );

                dp[i][1] = min( dp[i][1] , dp[i-1][0] + d + d );

                // taking all by l
                d = 0;

                for( auto j : seg[i] )
                    d = max( d , j.f - a[i-1] );
                assert(d >= 0 );

                dp[i][1] = min( dp[i][1] , min( dp[i-1][0] + d + d , dp[i-1][1] + d ) );
                dp[i][0] = min( dp[i][0] , min( dp[i-1][0] + d + d , dp[i-1][1] + d ) );

                // mixing
                if( seg[i].size() < 2 ) continue;

                vector<ll> sf_mn_r(seg[i].size());
                for(int j=(int)seg[i].size()-1; j>=0; j--){
                    sf_mn_r[j] = seg[i][j].s;
                    if( j + 1 < (int)seg[i].size() )
                        sf_mn_r[j] = min( sf_mn_r[j] , sf_mn_r[j+1] );
                }

                ll d1 = 1ll * mod * mod;
                ll d2 = 1ll * mod * mod;
                ll d3 = 1ll * mod * mod;
                ll d4 = 1ll * mod * mod;
                for(int j=0; j<(int)seg[i].size()-1; j++){
                    d1 = min( d1 , ( seg[i][j].f - a[i-1] ) + ( a[i] - sf_mn_r[j+1] ) );
                    d3 = min( d3 , ( seg[i][j].f - a[i-1] ) * 2ll + ( a[i] - sf_mn_r[j+1] ) );
                    d2 = min( d2 , ( seg[i][j].f - a[i-1] ) + ( a[i] - sf_mn_r[j+1] ) * 2ll );
                    d4 = min( d4 , ( seg[i][j].f - a[i-1] ) * 2ll + ( a[i] - sf_mn_r[j+1] ) * 2ll );
                }
                assert( d1 <= d2 );
                assert(d1 >= 0 );
                assert(d2 >= 0 );
                dp[i][0] = min( dp[i][0] , dp[i-1][1] + d1 );
                dp[i][0] = min( dp[i][0] , dp[i-1][0] + d3 );
                dp[i][1] = min( dp[i][1] , dp[i-1][1] + d2 );
                dp[i][1] = min( dp[i][1] , dp[i-1][0] + d4 );

                assert( dp[i][0] <= dp[i][1] );
            }

            ll ans = 0, ans2 = 0;
            if( seg[n].empty() ){
                cout << dp[n-1][0] << '\n';
                continue;
            }
            else{
                for( auto i : seg[n] ){
                    ans = max( ans , dp[n-1][1] + i.f - a[n-1] );
                    ans2 = max( ans2 , dp[n-1][0] + ( i.f - a[n-1] ) * 2ll );
                }
            }
            cout << min( ans , ans2 ) << '\n';
        }

        return 0;
    }