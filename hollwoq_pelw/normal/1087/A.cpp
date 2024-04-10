#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

string s;

void solve(){
    cin >> s;
    int n = s.length();
    int mid = (n-1)/2;
    cout << s[mid];
    int i = mid-1, j=mid+1;
    bool t = true;
    while(i>=0 || j<=n-1){
        if(t){
            cout<<s[j];
            j++;
        }
        else{
            cout<<s[i];
            i--;
        }
        t ^= 1;
    }
}

int main(){
    IOS;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}