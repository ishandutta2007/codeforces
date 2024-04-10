/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e7 + 10;
int freq[N]={0}, cnt[N]={0}, dp[N];

vector<int> isprime(N , true);
vector<int> prime;
vector<int> SPF(N);

// function generate all prime number less then N in O(n)
int manipulated_seive()
{
    isprime[0] = isprime[1] = false ;
    for (int i=2; i<N ; i++)
    {
        if (isprime[i]) { prime.push_back(i); SPF[i] = i; }
        for (int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    return 0;
}
int implement_ms = manipulated_seive();

vector<int> divisors(int x)
{
    vector<int> div = {1};
    while (x > 1) {
        int p = SPF[x], c = 0;
        while (x % p == 0) {
            x /= p, c += 1;
        }
        int sz = (int) div.size();
        for (int i = 1, pw = p; i <= c; i++, pw *= p) {
            for (int j = 0; j < sz; j++) {
                div.push_back(div[j] * pw);
            }
        }
    }
    return div;
}

void solve()
{
    int n, mx=0;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x; mx=max(mx, x);
        vector<int> d = divisors(x);
        for(int y: d) cnt[y]++;
    }

    for(int i=mx; i>=1; i--)
    {
        dp[i]=(cnt[i]*i);
        for(int x: prime)
        {
            int j = x*i;
            if(j>mx) break;
            dp[i] = max(dp[i], dp[j]+(cnt[i]-cnt[j])*i);
        }
    }

    int ans = dp[1];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}