#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7;

int main()
{
    int n;
    scanf("%d\n",&n);
    string s;
    cin>>s;
    long long ans = 0;
    for (int i=0;i<n;i++)
    for (int j=i;j<n;j++){

        int l,r,u,d;
        l = r = u = d = 0;
        for (int k=i;k<=j;k++){
            if (s[k] =='R')
                r++;
            if(s[k]=='L')
                l++;
            if(s[k]=='U')
                u++;
            if (s[k]=='D')
                d++;
        }
        if (r==l&&u==d)
            ans++;
    }
    cout<<ans;
	return 0;
}