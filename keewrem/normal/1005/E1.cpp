#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M;
int p[500000];
int d[500000];
int main(){
    cin >> N >> M;
    vector<int> v(N);
    int pos;
    for(auto &x: v){cin >> x;}
    int c = 0, k = 0;
    for(int i = 0; i < N; i++){
        if(v[i]==M)pos = i;
        
    }
    ll ans = 0;
    for(int i = pos; i < N; i++){
        
        if(v[i]>M)c++;
        else if(v[i]!= M) c--;
        if(i & 1)d[210000-c]++;
        else p[210000-c]++;
    }
    c=0; int x;
    for(int i = pos; i >= 0; i--){
        x = v[i];
        if(v[i]>M)c++;
        else if(x != M) c--;
     //   cout << "c "<<c << "\n";
       ans += p[210000+c] + d[210000+c];
        if(i & 1){
            ans += p[209999+c];
        }else ans += d[209999+c];
    }
    c = 0;
    //for(auto x: p) cout << x  << " "; cout << "\n";
    //for(auto x: d) cout << x  << " "; cout << "\n";
    
   cout << ans;
    return 0;
}