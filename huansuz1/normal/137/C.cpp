#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>

#define ll long long
#define mp make_pair
#define f first
#define s second



using namespace std;
int n,x,y,ans,q,m=123456789;
set < pair < int , int > > a;

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>x>>y;
        m=min(m,x);
        a.insert(mp(x,y));
    }
            
    for (set<pair<int, int> > :: iterator  it = a.begin(); it!=a.end(); it++) {
        if ((it -> f)!=m && (it -> s) < q) ans++;   
        q = max((it -> s),q); 
    }
    cout<<ans;

    
    return 0;
}