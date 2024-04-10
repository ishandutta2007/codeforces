#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
const int maxN = 2e5 + 5;
const int KK = 1e7;
int prm[10000005]; // prm[i] is prime i'th, like 1st, 2nd...
bool chk[10000005]; // the check row, to see if i is a prime or not
int k[KK + 1];
int n;
int a[maxN];
set<int> st;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int cnt = 0;
	for(int i = 0; i <= 10000000; i++){
	    chk[i] = 1;
	}
	for(int i = 2; i <= 10000000; i++){
	    if(chk[i]){
	        prm[cnt] = i; cnt++;
	        for(int j = 2 * i; j <= 10000000; j += i){
	            chk[j] = 0;
	        }
	    }
	}
	for(int i = 1; i <= KK; i++){
	    k[i] = i;
	}
	for(int i = 2; i <= KK; i++){
	    if(chk[i]){
	        for(int j = 2; j <= KK / i; j++){
	            while(k[i * j] % (i * i) == 0) k[i * j] /= i * i;
	        }
	    }
	}
// 	for(int i = 1; i < 19; i++){
// 	    cout << k[i] << endl;
// 	}
	int o; cin >> o;
	while(o--){
	    cin >> n >> a[0];
	    for(int i = 1; i <= n; i++){
	        cin >> a[i];
	        a[i] = k[a[i]];
	    }
	    ans = 1;
	    st.clear();
	    for(int i = 1; i <= n; i++){
	        if(st.find(a[i]) == st.end()) st.insert(a[i]);
	        else{
	            ans++;
	            st.clear();
	            st.insert(a[i]);
	        }
	    }
	    cout << ans << endl;
	    // cout << n << endl;
	}

}