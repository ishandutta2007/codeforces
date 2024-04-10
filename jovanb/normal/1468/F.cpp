#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int N = 1e5+45;
const ld pi = acosl(-1);
const ld eps = 1e-13;
 
ll n,x[N],y[N],u[N],v[N];
vector <ld> vec;
 
ll ima(ld g){
    int l = 0,r = n-1,levo = -1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(vec[mid] >= g-eps){
            levo = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
 
    //cout << "g je " << g << " " << levo << endl;
 
    if(levo == -1) return 0;
 
    l = 0,r = n-1;
    int desno = -1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(vec[mid] <= g+eps){
            desno = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
 
    //cout << " i " <<desno << endl;
    if(desno == -1) return 0;
 
    return desno-levo+1;
}
 
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> u[i] >> v[i];
    }
 
    vec.clear();
    for(int i = 1; i <= n; i++){
        if(u[i] == x[i]){
            if(v[i] > y[i]){
                vec.push_back(ld(3)*(pi/ld(2)));
            }
            else{
                vec.push_back(pi/ld(2));
            }
            continue;
        }
        if(v[i] == y[i]){
            if(u[i] > x[i]){
                vec.push_back(0);
            }
            else{
                vec.push_back(pi);
            }
            continue;
        }
 
        if(u[i] > x[i]){
            if(v[i] < y[i]){
                ld ugao = atanl(ld(y[i]-v[i])/ld(u[i]-x[i]));
                vec.push_back(ugao);
            }
            else{
                ld ugao = ld(2)*pi-atanl(ld(v[i]-y[i])/ld(u[i]-x[i]));
                vec.push_back(ugao);
            }
        }
        else{
            if(v[i] < y[i]){
                ld ugao = pi-atanl(ld(y[i]-v[i])/ld(x[i]-u[i]));
                vec.push_back(ugao);
            }
            else{
                ld ugao = pi+atanl(ld(v[i]-y[i])/ld(x[i]-u[i]));
                vec.push_back(ugao);
            }
        }
 
        assert(vec.back() >= 0);
    }
    sort(vec.begin(), vec.end());
    /*for(auto f : vec){
        cout << f << " ";
    }
    cout << endl;*/
 
    ll sol = 0;
 
    for(auto f : vec){
        sol += ima(f-pi);
        sol += ima(f+pi);
    }
 
    cout << sol/2 << endl;
}
 
int main(){
    cout.precision(10);
    cout << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}