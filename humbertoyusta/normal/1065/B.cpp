#include<bits/stdc++.h>
using namespace std;

long long n,m;
set<long long> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    s.insert(0);
    for(long long i=1; i<141421;i++)
       s.insert(i*(i+1)/2);

    cin >> n >> m;

    if(m==0){
        cout << n << ' ' << n;
        return 0;
    }

    set<long long>::iterator o = s.lower_bound(m-1);
    if( *o >= m ) o--;

    cout << max(0LL,n-2*m) << ' ';

    cout << max(0LL, n - ( distance(s.begin(),o) + 2 ) );

    return 0;
}