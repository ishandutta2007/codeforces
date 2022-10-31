#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 2000007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n,all = 0,pref[DIM];
string ans = "";
void kmp(string s){
    for(ll i = 1;i<s.length();i++){
        ll j = pref[i-1];
        while(s[i]!=s[j] && j>0)j = pref[j-1];
        if (s[i]==s[j])j++;
        pref[i] = j;
    }
}
int main() {
	schnell;
    cin>>n;
    forn(i,n){
        string s;
        cin>>s;
        string d;
        if (ans.length()<s.length()){
            d = s.substr(0,ans.length())+"#"+ans;
        }
        else{
            d = s+"#"+ans.substr(ans.length()-s.length(),s.length());
        }
        kmp(d);
        ll cof = pref[d.length()-1];
        ans+=s.substr(cof,s.length()-cof);
    }
    cout<<ans<<endl;
	return 0;
}