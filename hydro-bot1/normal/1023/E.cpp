// Hydro submission #62c6d5248672efa577c02203@1657197861608
#include<bits/stdc++.h>
using namespace std;

#define int long long   
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;
typedef long double lld;

void setIO(string s) { 
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int N=1e3+1, M=1e5+1, mod=1e9+7, inf = 1e17, moda = 998244353;


int binexp(int a, int b, int mod){

    assert(b>=0);
    a=a%mod;
    int ans = 1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

bool com(pair<int, char> a, pair<int, char> b){
    return a.second<b.second;
}

int accurateFloor(int a, int b) {
    int val = a / b;
    while (val * b > a)
        val--;
    return val;
}

void solve(){
    int n;
    cin>>n;

    string top, bot;
    int r = 1, c = 1;
    for(int i=0; i<n-1; i++){
        cout<<"? "<<r+1<<" "<<c<<" "<<n<<" "<<n<<endl;
        string s;
        cin>>s;

        if(s == "YES"){
            r++;
            top+="D";
        }else{
            c++;
            top+="R";
        }
    }

    r = n, c = n;
    for(int i=0; i<n-1; i++){
        cout<<"? "<<1<<" "<<1<<" "<<r<<" "<<c-1<<endl;
        string s;
        cin>>s;

        if(s == "YES"){
            c--;
            bot+="R";
        }else{
            r--;
            bot+="D";
        }
    }

    reverse(all(bot));

    cout<<"! "<<top<<bot<<endl;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    
    cout<<setprecision(15)<<fixed;

    solve();
}