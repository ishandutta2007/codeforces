
#include <bits/stdc++.h>
const int maxn=40;
const int inf=2e9;
const int eps=1e-9;
const int base=1e9+7;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;
int a[maxn];
int main()
{
    int n;

  //          freopen("input.txt","r",stdin);
//             freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    set<int> tk;
    ll sum = 0;
    for (int i=0;i<n;i++){
        int mx = a[i];
        if (tk.count(mx)){
            mx = *tk.begin();
            mx--;
            if (mx>0)
                {
                    sum+=1LL*mx;
                    tk.insert(mx);
                }
        } else
        {
            sum+=1LL*mx;
            tk.insert(mx);
        }
    }
    cout<<sum;
        return 0;
}