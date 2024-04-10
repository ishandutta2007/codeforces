#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe

//#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM];
string OR = "OR",XOR = "XOR",AND = "AND";
ll ask(string s,ll a,ll b){
    cout<<s<<' '<<a<<' '<<b<<endl;
    ll ans;
    cin>>ans;
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 2;i<=n;++i){
        A[i] = ask(XOR,1,i);
    }

    ll or1 = ask(OR,1,2);
    ll or2 = ask(OR,1,3);
    ll and1 = ask(AND,2,3);

    ll a = 0;
    ll mult = 1;
    ll b = A[2];
    ll c = A[3];
    for(ll y = 1;y<=17;++y){
        if ((b&1) && (c&1)){
            if (!(and1&1))a+=mult;
        }
        else if (!(b&1) && !(c&1)){
            if (or1&1)a+=mult;
        }
        else{
            if (b&1){
                if (or2&1)a+=mult;
            }
            else{
                if (or1&1)a+=mult;
            }
        }
        mult*=2;
        or1/=2;
        or2/=2;
        c/=2;
        b/=2;
        and1/=2;
    }
    cout<<"! ";
    cout<<a<<' ';
    for(ll i = 2;i<=n;++i){
        cout<<(A[i]^a)<<' ';
    }
    cout<<endl;
    return 0;
}