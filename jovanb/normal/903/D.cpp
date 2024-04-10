#include <bits/stdc++.h>

using namespace std;
long long niz[500000],sum[500000];
unordered_map <long long, long long> br;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n;
    long long brne,i;
    long double z=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>niz[i];
        if(i>1){
            brne=br[niz[i]]+br[niz[i]-1]+br[niz[i]+1];
            brne=i-1-brne;
            z+=brne*niz[i]-(sum[i-1]-br[niz[i]]*niz[i]-br[niz[i]-1]*(niz[i]-1)-br[niz[i]+1]*(niz[i]+1));
        }
        sum[i]=niz[i]+sum[i-1];
        br[niz[i]]++;
    }
    cout<<fixed<<setprecision(0)<<z;
    return 0;
}