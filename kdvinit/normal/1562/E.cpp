/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5005;
int same[N][N];     //same[i][j] -> (i<j) number of characters same from i and j else -1

string s;
int n;

int less_than(int i, int j)       //true if i < j
{
    int same=0;
    while(1)
    {
        if(i==n) return same;
        if(j==n) return -1;
        if(s[i]<s[j]) return same;
        if(s[i]>s[j]) return -1;
        i++; j++; same++;
    }
}

void set_same()
{
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) same[i][j]=0;

    for(int j=n-1; j>=0; j--)
    {
        for(int i=j-1; i>=0; i--)
        {
            if(s[i]!=s[j])
            {
                if(s[i]>s[j]) same[i][j]=-1;
                else same[i][j]=0;
            }
            else
            {
                int tmp = same[i+1][j+1];
                if(tmp==-1) same[i][j]=-1;
                else same[i][j]=tmp+1;
            }
        }
    }
}

int get_ans()
{
    int dp[n]={0}, ans=0;
    for(int i=0; i<n; i++)
    {
        int val=0;
        for(int j=0; j<i; j++)
        {
            int tmp = same[j][i];
            if(tmp==-1) continue;
            tmp = dp[j]-tmp;
            val = max(val, tmp);
        }
        val+=(n-i); dp[i]=val;
        ans = max(ans, val);
    }
    return ans;
}

void solve()
{
    cin>>n>>s;
    set_same();
    int ans = get_ans();
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}