    #include<bits/stdc++.h>
    #define inf 1000000007
    #define maxn 200005
    using namespace std;

    int tc, n1, n2, n3, n, a[4][maxn], cnt[4][maxn], ans, mx[maxn];

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

            cin >> n1 >> n2 >> n3;
            n = n1 + n2 + n3;
            ans = inf;
            mx[0] = 0;

            for(int i=1; i<=n; i++){
                cnt[1][i] = cnt[2][i] = cnt[3][i] = 0;
            }

            for(int i=1; i<=n1; i++)
                cin >> a[1][i], cnt[1][a[1][i]]++;
            for(int i=1; i<=n2; i++)
                cin >> a[2][i], cnt[2][a[2][i]]++;
            for(int i=1; i<=n3; i++)
                cin >> a[3][i], cnt[3][a[3][i]]++;

            for(int i=1; i<=n+1; i++){
                cnt[1][i] += cnt[1][i-1];
                cnt[2][i] += cnt[2][i-1];
                cnt[3][i] += cnt[3][i-1];

                mx[i] = max( mx[i-1] , cnt[1][i] - cnt[2][i] );
            }

            for(int i=0; i<=n+1; i++){
                ans = min( ans , n - cnt[3][n] - mx[i] - ( cnt[2][i] - cnt[3][i] ) );
            }

            cout << ans << '\n';

        return 0;
    }