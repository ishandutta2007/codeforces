#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1000+7;
ll A[DIM][DIM],flag[2][DIM];
ll n,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>m;
        for(ll i = 1;i<=n;++i){
            flag[0][i] = flag[1][i] = 0;
            for(ll j = 1;j<=n;++j){
                char ch;
                cin>>ch;
                if (ch=='a')A[i][j] = 1;
                else A[i][j] = 2;
            }
        }
        if (m%2!=0){
            cout<<"YES\n";
            for(ll i = 1;i<=m+1;++i){
                cout<<1ll+i%2<<' ';
            }
            cout<<endl;
            continue;
        }
        pair<ll,ll> pp;
        ll ff = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){
                if (j==i)continue;
                if (A[i][j]==1)flag[0][i] = j;
                if (A[i][j]==2)flag[1][i] = j;
                if (A[i][j]==A[j][i]){
                    ff = 1;
                    pp = {i,j};
                }
            }
        }
        if (ff){
            cout<<"YES\n";
            for(ll i = 1;i<=m+1;++i){
                if (i%2)cout<<pp.first<<' ';
                else cout<<pp.second<<' ';
            }
            cout<<endl;
            continue;
        }
        else{
            ll q=-1,b,c;
            for(ll i = 1;i<=n;++i){
                for(ll j = 1;j<=n;++j){
                    if (i==j)continue;
                    if (flag[A[i][j]-1][j]){
                        q = i,b = j,c = flag[A[i][j]-1][j];
                        break;
                    }
                }
            }
            if (q==-1){
                cout<<"NO\n";
                continue;
            }
            deque<ll> Q;
            ll a[] = {q,b,c};
            ll ptr1 = 0,ptr2 = 2,delta1 = 1,delta2 = -1;
            Q.push_back(q);
            Q.push_back(b);
            Q.push_back(c);
            while(Q.size()<=m){
                ptr2+=delta2;
                ptr1+=delta1;
                if (ptr2==0)delta2 = 1;
                if (ptr2==2)delta2 = -1;
                if (ptr1==0)delta1 = 1;
                if (ptr1==2)delta1 = -1;
                Q.push_back(a[ptr2]);
                Q.push_front(a[ptr1]);
            }
            cout<<"YES\n";
            for(ll to:Q)cout<<to<<' ';
            cout<<endl;
        }

    }
    return 0;
}