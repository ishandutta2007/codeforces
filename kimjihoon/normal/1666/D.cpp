#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=250020;
const int MOD=1e9+7;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
int N, M;
char S1[mxN], S2[mxN];
int cnt[30];
stack <char> ans;
void init()
{
    while(ans.size())  ans.pop();
    for(int i=0;i<26;i++)   cnt[i]=0;
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> S1 >> S2;
        N=strlen(S1), M=strlen(S2);
        for(int i=0;i<M;i++)
        {
            cnt[S2[i]-'A']++;
        }
        for(int i=N-1;i>=0;i--)
        {
            if(cnt[S1[i]-'A'])
            {
                cnt[S1[i]-'A']--;
                ans.push(S1[i]);
            }
        }
        if(ans.size()!=M)   cout << "NO\n";
        else
        {
            bool ok=true;
            for(int i=0;i<M;i++)
            {
                if(ans.top()!=S2[i])
                {
                    cout << "NO\n";
                    ok=false;
                    break;
                }
                else
                {
                    ans.pop();
                }
            }
            if(ok)  cout << "YES\n";
        }
        init();
    }
}