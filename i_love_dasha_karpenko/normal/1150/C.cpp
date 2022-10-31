#include <bits/stdc++.h>

using namespace std;
#define DIM 10008
#define INF 10E16
#define MAXN 400007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[MAXN];
ll n,l1 = 0,l2 = 0,pos=0;
arr A;

int can(ll x){
    ll r = x-pos;
    if (l1==0 && r%2!=0){
        return 0;
    }
    if (l1+l2*2>=r)return 1;
    return 0;
}

void done(ll x){
    while(pos!=x){
        if (l2!=0 && x-pos>=2){
            l2--;
            pos+=2;
            cout<<2<<' ';
            continue;
        }
        else{
            l1--;
            pos++;
            cout<<1<<' ';
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("shortcut.in","r",stdin);
    //freopen("shortcut.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll x;
    for (int i = 1;i<=n;i++){

        cin>>x;
        if (x==1)l1++;
        else l2++;
    }
    for (ll i = 2;i<MAXN && (l1>0 || l2>0);i++){
        if (A[i]==0){
            for (ll j = i*i;j<MAXN;j+=i)A[j]=1;
            if (can(i))
                done(i);




        }
    }
    for (ll j = 1;j<=l1;j++){
                    cout<<1<<' ';
                }
                for (ll j = 1;j<=l2;j++){
                    cout<<2<<' ';
                }
                return 0;
}