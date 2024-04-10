#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;
string a,b;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        cin >> a >> b;
        vi sol;
        for(int i = N-1; i >= 0; i--){
            if(a[i]==b[i])continue;
            if(a[0]==b[i]){
                sol.pb(1);
                a[0]=2*'1'-1-a[0];
            }
            sol.pb(i+1);
            for(int j = 0; j < i/2+1; j++){
                swap(a[j],a[i-j]);
                a[j]=2*'1'-a[j]-1;
                if(j!=i-j)a[i-j]=2*'1'-a[i-j]-1;
            }
        }
        cout << sol.size();
        for(auto x: sol)cout<<" " << x;
        cout << "\n";
    }
    return 0;
}