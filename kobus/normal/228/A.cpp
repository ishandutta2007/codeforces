#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 112
#define INF LLONG_MAX/4
#define double long double
#define int long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    cout<<4-s.size()<<endl;


    return 0;
 
}