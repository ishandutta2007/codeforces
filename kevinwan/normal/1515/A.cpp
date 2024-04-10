#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;

int a[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int sum=0;
        vi ans;
        bool u=0,fail=0;
        for(int i=0;i+u<n;){
            if(!u && sum+a[i]==x){
                if(sum+a[n-1]==x){
                    fail=1;
                    break;
                }
                sum+=a[n-1];
                ans.push_back(a[n-1]);
                u=1;
            }
            sum+=a[i];
            ans.push_back(a[i]);
            i++;
        }
        if(fail)printf("NO\n");
        else{
            printf("YES\n");
            for(int x:ans)printf("%d ",x);
            printf("\n");
        }
    }
}