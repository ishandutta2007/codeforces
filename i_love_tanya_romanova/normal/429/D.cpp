#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define ll long long
#define pb push_back
#define pow hi1
#define bro pair<int, int>
#define all(a) (a).begin(), (a).end()

const int N=100005;
int ans, l, r, x, t, q, m, s[N], pow[N], n, i, j;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        s[i]=s[i-1]+x;
    }
    for(i=0; i<=10000; i++)
        pow[i]=i*i;
    ans=1e9;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n&&j<=i+10000; j++)
        {
            t=(j-i);
            q=abs(s[j]-s[i]);
            if(q<=10000)ans=min(ans, pow[q]+pow[t]);
        }
    }
    cout<<ans<<endl;
}