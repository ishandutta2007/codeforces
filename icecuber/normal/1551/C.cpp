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
    return aa.val - aa.ix < bb.val-bb.ix;
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
        ll n,k,sum,nbw,maxnbw;
        cin>>n;
        vector<s_ix> nb(n);
        vector<string> s(n);
        for (int j=0;j<n;j++)cin>>s[j];
        //cout<<n<<endl;
        maxnbw=0;
        for (int l=0;l<26;l++){
            nbw=0;
            for (int j=0;j<n;j++){
                nb[j].val=0;
                nb[j].ix=0;
                for (int jj=0;jj<s[j].size();jj++){
                    if(s[j][jj]-'a'==l)nb[j].val++;
                    else nb[j].ix++;
                }
            }
            sort(nb.rbegin(),nb.rend());
            ll nl=0;
            int j=0;
            //cout<<j<<" "<<nbw<<" "<<nl<<" "<<nb[j].val<<" "<<nb[j].ix<<endl;
            while(j<n){
                nl+=nb[j].val -nb[j].ix;
                if(nl<=0)break;
                j++;
                nbw++;
                //cout<<j<<" "<<nbw<<" "<<nl<<" "<<nb[j].val<<" "<<nb[j].ix<<endl;
            }
            maxnbw=max(maxnbw,nbw);
 
        }
        cout<<maxnbw<<endl;
    }
}