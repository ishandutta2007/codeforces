#include <bits/stdc++.h>
using namespace std;
#include <string>
typedef long long ll;
//-Wfatal-errors
// node=vertex . edges connect vertices
//alias d++='g++ -std=c++17 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g '
//const double PI=acos(-1.0);
//cout << setprecision(20) << x << endl;

struct s_ix {
    ll ix;
    ll val;
};
bool operator<(s_ix  aa, s_ix  bb) {
    return aa.val < bb.val;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll T;
    //next_permutation
    //set<ll> pos;
    //if(pos.count()>0){
    //  pos.insert(a);}
    //assert(true);//ok
    //assert(false);//fails

    //T=1;
    cin>>T;
    // for (int j=0;j<n;j++)cin>>a[j];
    while(T--){
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>> v(n);
        vector<ll> a(n+1), c(n+1, -1), s(n);
        for (int j=0;j<n;j++)cin>>s[j];
        for (int j=0;j<n;j++)a[s[j]-1]++;
        for (int j=0;j<n;j++)v[s[j]-1].push_back(j);
        ll sum=0;
        for (int j=0;j<n;j++)if(v[j].size()>k)sum+=v[j].size()-k;
        ll cnt=0;
        ll nb = (n-sum)/k; // number of elements with same color
        ll cntk=0;
        while(cnt<n){
            for (int j=0;j<v[cnt].size();j++){
                if(j<k and cntk<nb*k){
                    c[v[cnt][j]]=cntk%k+1;
                    cntk++;
                }else{
                    c[v[cnt][j]]=0;
                }
            }
            cnt++;
        }

       //a[j] number of elements with value j
        for (int j=0;j<n;j++)cout<<c[j]<<" ";

        cout<<endl;
    }
}