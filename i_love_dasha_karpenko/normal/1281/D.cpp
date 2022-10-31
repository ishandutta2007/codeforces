#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 60+7;
const ll INF = 10E18+173;
const ll MOD = 10E8+7;


ll gi(char ch){
    if (ch=='A')return 1;
    else return 0;
}
ll A[DIM][DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,m; cin>>n>>m;
        ll sum = 0;
        forn(i,n){
            forn(j,m){
                char ch; cin>>ch;
                A[i][j] = gi(ch);
                sum+=A[i][j];
            }
        }
        if (sum==0){
            cout<<"MORTAL"<<endl;
            continue;
        }
        if (sum==n*m){
            cout<<0<<endl;
            continue;
        }
        ll ff = 1,flag = 0;
        forn(i,n){
            if (A[i][1]!=1){
                flag = 1;
                break;
            }
        }
        ff = min(ff,flag);
        flag = 0;
        forn(i,n){
            if (A[i][m]!=1){
                flag = 1;
                break;
            }
        }
        ff = min(ff,flag);
        //
        flag = 0;
        forn(j,m){
            if (A[1][j]!=1){
                flag = 1;
                break;
            }
        }
        ff = min(ff,flag);
        flag = 0;
        forn(j,m){
            if (A[n][j]!=1){
                flag = 1;
                break;
            }
        }
        ff = min(ff,flag);
        if (ff==0){
            cout<<1<<endl;
            continue;
        }
        ll rf = 1;
        forn(i,n){
            ll flag = 0;
            forn(j,m){
                if (A[i][j]==0){
                    flag = 1;
                    break;
                }
            }
            rf = min(rf,flag);
        }
        forn(j,m){
            ll flag = 0;
            forn(i,n){
                if (A[i][j]==0){
                    flag = 1;
                    break;
                }
            }
            rf = min(rf,flag);
        }
        if (rf==0 || A[1][1]==1 || A[1][m]==1 || A[n][1]==1 || A[n][m]==1){
            cout<<2<<endl;
            continue;
        }
        flag = 0;
        forn(i,n){
            if (A[i][1]==1)flag=1;
            if (A[i][m]==1)flag=1;
        }
        forn(j,m){
            if (A[1][j]==1)flag = 1;
            if (A[n][j]==1)flag = 1;
        }
        if (flag==1){
            cout<<3<<endl;
            continue;
        }
        cout<<4<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3