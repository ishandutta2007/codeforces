#include <bits/stdc++.h> //  l   ( 2  ) ,   3

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 3e5+5, base = 1e9+7,maxm=1e6+500;
    int a[maxn],st[maxn];
    int sum[maxn] = {0};
int main()
{

   // files1;
   // files2;
    fast_io;

    string s;
    cin>>s;
    for (int i=0;i<s.size();i++){
        a[i] = s[i] - '0';
    }
    int n  = s.size();
    ll ans = 0;
    for (int i=0;i<n-1;i++){
        if ((a[i]*10+a[i+1])%4==0){
            st[i] = 1;
        }
        if (a[i] == 4 || a[i] == 0 || a[i] == 8)
            ans++;
    }
    if (a[n-1] == 4 || a[n-1] == 0 || a[n-1] == 8)
        ans++;
    for (int i=n-1;i>=0;i--){
        sum[i] = sum[i+1] + st[i];
    }
    for (int i=0;i<n;i++){
     //   cerr<<sum[i]<<endl;
        ans += sum[i];
    }
    cout<<ans;
	return 0;

}