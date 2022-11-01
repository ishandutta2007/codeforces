#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ll long long

const int maxn = 2e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;
int a[maxn];

int main()
{
    fast_io;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    for (int k=0;k<n;k++){
        if (i!=j && i!=k && j!=k){
            if (a[i] != a[j] && a[i]!=a[k] &&a[j]!=a[k]){
                if (abs(a[i] - a[j]) <= 2 && abs(a[i] - a[k]) <= 2 && abs(a[j] - a[k]) <= 2){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}