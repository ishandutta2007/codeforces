//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
//#define endl '\n'
const ll DIM = 1000+7;
const ll MOD = 1E9+7;
ll A[DIM];
struct node{
    ll dif,a,b;
};
bool mc(const node &a,const node &b){
    return a.dif>b.dif;
}
ll ask(ll a,ll b){
    cout<<"? "<<a<<' '<<b<<endl;
    string ans;
    cin>>ans;
    return ans=="Yes";
}
int main()
{
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i) {
        cin >> A[i];
        A[i] = n - A[i];
    }
    //sort(A+1,A+1+n);
    vector<node> V;
    for(ll i = 1;i<=n;++i){
        for(ll j = i+1;j<=n;++j)
            V.push_back({abs(A[i]-A[j]),i,j});
    }
    sort(V.begin(),V.end(),mc);
    for(auto to:V){
        if (A[to.a]>A[to.b])swap(to.a,to.b);
        if (ask(to.a,to.b)){
            cout<<"! "<<to.a<<' '<<to.b<<endl;
            return 0;
        }

    }
    cout<<"! "<<0<<' '<<0<<endl;
    return 0;
}