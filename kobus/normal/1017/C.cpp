#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 3241618756

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    int val=INF;
    int vali;
    for(int i=1;i<=n;i++){
        if(((n+i-1)/i)+i<val){
            val=((n+i-1)/i)+i;
            vali=i;
        }
    }
    int lowest=n-vali+1;
    //cout<<vali<<endl;
    int at=lowest;
    set<int> foi;
    while(foi.size()<n){
        foi.insert(at);
        cout<<at<<" ";
        at++;
        if(foi.find(at)!=foi.end() || at>n){
            lowest=max(lowest-vali,1ll);
            at=lowest;
        }
    }
    cout<<endl;

    return 0;
}