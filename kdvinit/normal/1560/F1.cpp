/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> kk[3][10][11];

void solve()
{
    int n, k;
    cin>>n>>k;

    string nn = to_string(n);

    int y = nn[0]-'0';
    if(k==1) y=0;

    int m = nn.size();

    int ans = n*100, val=-1;
    for(auto x: kk[k][y][m])
    {
        if(x<n) continue;
        int tmp = x-n;
        if(tmp<ans)
        {
            ans = tmp;
            val = x;
        }
    }

    cout<<val<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int len=1; len<=10; len++)
    {
        for(int i=0; i<10; i++)
        {
            int x = len;
            int num = 0;
            while(x--) { num*=10; num+=i; }
            kk[1][0][len].push_back(num);
        }
    }

    for(int len=1; len<=10; len++)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                int mx = 1<<(len);
                for(int bm=0; bm<mx; bm++)
                {
                    int num = 0;
                    int x = len;
                    int y = bm;
                    while(x--)
                    {
                        num*=10;
                        if(y%2==1) num+=i;
                        else num+=j;
                        y/=2;
                    }
                    kk[2][i][len].push_back(num);
                }
            }
        }
    }

    int t; cin>>t;
    while(t--) solve();
    return 0;
}