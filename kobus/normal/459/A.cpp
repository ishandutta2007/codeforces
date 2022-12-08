#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF numeric_limits<ll>::max()
#define MOD 998244353
#define eps 1e-15
#define eeps
#define cood long double


int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    pii a,b;
    cin>>a.f>>a.s>>b.f>>b.s;
    int max1=max(a.f,b.f);
    int min1=min(a.f,b.f);
    int max2=max(a.s,b.s);
    int min2=min(a.s,b.s);
    if(max1!=min1 && max2!=min2 && abs(max1-min1)!=abs(max2-min2)){
        cout<<-1<<endl;
        return 0;
    } 
    int dif=max(abs(max1-min1),abs(max2-min2));
    if(max1==min1)max1=min1+dif;
    if(max2==min2)max2=min2+dif;
    pii p1={min1,min2};pii p2={min1,max2};
    pii p3={max1,min2};pii p4={max1,max2};
    if(p1!=a&&p1!=b)
        cout<<p1.f<<" "<<p1.s<<" ";
    if(p2!=a&&p2!=b)
        cout<<p2.f<<" "<<p2.s<<" ";
    if(p3!=a&&p3!=b)
        cout<<p3.f<<" "<<p3.s<<" ";
    if(p4!=a&&p4!=b)
        cout<<p4.f<<" "<<p4.s<<" ";
    cout<<endl;
}