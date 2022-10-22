#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(15);
    cout<<fixed;

    int n, u;
    cin >> n >> u;
    for(int i=0; i<n; i++) cin >> niz[i];
    int r = 2;
    ll maxi=-1, maxj=-1, maxk=-1;
    for(int i=0; i<n-2; i++){
        ll ei = niz[i];
        ll ej = niz[i+1];
        while(r <= i+1) r++;
        while(1){
            if(niz[r] > ei+u) break;
            else{
                if(maxi == -1){maxi = i; maxj = i+1; maxk = r;}
                else if((niz[r]-ej)*(niz[maxk]-niz[maxi]) > (niz[maxk]-niz[maxj])*(niz[r]-ei)){maxi = i; maxj = i+1; maxk = r;}
                if(r == n-1) break;
                if(niz[r+1] > ei+u) break;
                r++;
            }
        }
    }
    if(maxi == -1){cout << -1; return 0;}
    cout << ((niz[maxk]-niz[maxj])/(long double)(niz[maxk]-niz[maxi]));
    return 0;
}