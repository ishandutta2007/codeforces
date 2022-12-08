#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<long long,long long>
#define MAXN 21234
#define INF INT_MAX
#define double long double
#define pi acos(-1)
#define MOD 10000007
#define int unsigned long long
 
 
 
int32_t main () {
    ios_base::sync_with_stdio(false);
    cout<<setprecision(8)<<fixed;
 
    int n,m;
    cin>>n>>m;
    multiset<int> a;
    multiset<int> b;
    int sa=0;
    int sb=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sa+=x;
        a.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        sb+=x;
        b.insert(x);
    }
    int resp=sa+sb;
    int ca=0;
    do{
        resp=min(resp,ca+sb*((int)a.size()));
        int num=*a.begin();
        a.erase(a.begin());
        ca+=num;
    }while(a.size()>0);
    int cb=0;
    do{
        resp=min(resp,cb+sa*((int)b.size()));
        int num=*b.begin();
        b.erase(b.begin());
        cb+=num;
    }while(b.size()>0);
    cout<<resp<<endl;
 
    return 0;
}