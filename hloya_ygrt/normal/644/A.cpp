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
const int sz = 3;
const double eps=1e-9;
const int maxn = 1e3+500, base = 1e9+7,maxm= 10;

int ans[maxn][maxn];
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a*b){
        return puts("-1"),0;
    }
    int op = 1;
    for (int i=0;i<a;i++)
    for (int j=0;j<b;j++){
        if (op <= n)
        ans[i][j] = op++;
    }

    if (b % 2 == 0){
        for (int j=1;j<a;j+=2){
            for (int i=0;i+1<b;i+=2){
                swap(ans[j][i], ans[j][i+1]);
            }
        }
    }
    for (int i=0;i<a;i++){
    for (int j=0;j<b;j++)
            cout<<ans[i][j]<<' ';
            puts("");
    }
}