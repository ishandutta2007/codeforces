#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 10000000000000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];

ll n,cn = 0,cn1 = 0,res=0;

string s;
int main()
{
    //freopen("input.txt","r",stdin);

    cin>>n>>s;
    ll n1 = n;
    res=n;
    if ((n-11)%2!=0)n+=11;
    ll l = max(ll(0),(n-11)/2);

    int i = 0;
    while(l>0 && i<n1){
        if (s[i]!='8'){
            l--;
            s[i]=-1;
        }
        i++;
    }
    i = 0;
    n = n1;
     ll l1 = max(ll(0),(n-11)/2);
     l = l1;
    while(l>0 && i<n1){

        if (s[i]=='8'){
            s[i]=-1;
            l--;
        }
        i++;
    }
    for (int i= 0;i<n;i++){
        if (int(s[i])!=-1){
            if (s[i]=='8'){
                cout<<"YES"<<endl;

            }
            else{
                cout<<"NO"<<endl;
            }
            return 0;
        }
    }


}