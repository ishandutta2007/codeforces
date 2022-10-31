#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 1000000000007
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n;
set<ll> S;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll h=n,r=1;
    S.insert(h);
    while(1){
        while((h+1)%10!=0){
            h++;
            if (S.count(h)==1){
                goto link;
            }
            S.insert(h);
        }
        h++;

        while(h%10==0){h/=10;}
        if (S.count(h)==1)break;
        S.insert(h);
    }
    link:
    cout<<S.size()<<endl;
}