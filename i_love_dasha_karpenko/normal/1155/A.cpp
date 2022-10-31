#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 10000000000000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];

ll n;

string s;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    ll l = s.length();
    for (int i = 1;i<l;i++){
        if (s[i]<s[i-1]){
            cout<<"YES"<<endl;
            cout<<i<<' '<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}