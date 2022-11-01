#include <bits/stdc++.h>

#define f first
#define s second

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
const int maxn = 1e6+500, base = 1e9+7,maxm= 10;

int sum[maxn], t[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        sum[a]++;
        t[a] = i;
    }
    int ans = 1;
    for (int i=1;i<=1000000;i++){
           if (sum[i] > sum[ans]){
                ans = i;
           } else if (sum[i] == sum[ans] && t[i] < t[ans]){
                ans = i;
           }
    }
    cout<<ans;
}