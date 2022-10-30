#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e2+500, base = 1e9+7,maxm= 1e4+5;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    while (s.size() != 1)
    {
        ans++;
        int sum = 0;
        for (int i=0;i<s.size();i++)
            sum += s[i] - '0';
        s.clear();

        while (sum > 0)
        {
            s.pb(sum % 10 + '0');
            sum /= 10;
        }
        reverse(s.begin(), s.end());
    }
    cout<<ans;
}