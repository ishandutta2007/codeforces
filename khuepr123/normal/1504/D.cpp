#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

set<ii> st1;
set<ii> st2;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i + j) % 2 == 0) st1.insert(ii(i, j));
            else st2.insert(ii(i, j));
        }
    }
    while(1){
        if(st1.empty() && st2.empty()) return 0;
        cin >> k;
        if(k != 2){
            if(!st2.empty()){
                ii pr = (*st2.begin());
                st2.erase(pr);
                cout << "2 " << pr.fi << " " << pr.se << endl;
            }
            else{
                ii pr = (*st1.begin());
                st1.erase(pr);
                cout << 4 - k << " " << pr.fi << " " << pr.se << endl;
            }
        }
        else{
            if(!st1.empty()){
                ii pr = (*st1.begin());
                st1.erase(pr);
                cout << "1 " << pr.fi << " " << pr.se << endl;
            }
            else{
                ii pr = (*st2.begin());
                st2.erase(pr);
                cout << 3 << " " << pr.fi << " " << pr.se << endl;
            }
        }
    }
}