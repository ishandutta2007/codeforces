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

int a[150001];

int main()
{
    int n,k,q;
    scanf("%d %d %d", &n, &k, &q);
    for (int i=0;i<n;i++)
        scanf("%d", a + i);
    vector<int> now;
    for (int i=0;i<q;i++){
        int t, it;
        scanf("%d %d", &t, &it);
        if (t == 1){
            now.pb(a[it-1]);
            sort(now.begin(), now.end());
            if (now.size() > k)
                now.erase(now.begin());
        } else
        {
            bool flag = 0;
            for (int j=0;j<now.size();j++)
                if (now[j] == a[it-1]){
                    flag = 1;
            }
            if (flag)
                puts("YES");
            else
                puts("NO");
        }

    }
    return 0;
}