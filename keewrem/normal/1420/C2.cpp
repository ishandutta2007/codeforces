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
ll N,Q;
int a,b;
vi v;
int kek(int i){
    if (i < 0 || i >= N)return 0;
    if((i == 0 || v[i] > v[i-1]) && (i == N-1 || v[i] > v[i+1]))return v[i];
    if((i > 0 && v[i] < v[i-1]) && (i < N-1 && v[i] < v[i+1]))return -v[i];
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        //cout << "-------------------\n";
        cin >> N >> Q;
        v.resize(N);
        for(auto &x: v)x=0;
        for(auto &x: v)cin >> x;
        ll res = 0;
        for(int i = 0; i < N; i++){
            res+=kek(i);
        }
        set<int> s;
        cout << res <<"\n";
        while(Q--){
            cin >> a >> b;
            a--; b--;
            s.clear();
            s.insert(a);s.insert(a-1);s.insert(a+1);
            s.insert(b);s.insert(b-1);s.insert(b+1);
            for(auto x: s)res-=kek(x);//cout << x <<" "<<kek(x)<<"\n";}
        //    cout << "\n";
            swap(v[a],v[b]);
            for(auto x: s)res+=kek(x);//cout << x <<" "<<kek(x)<<"\n";}
            cout << res << "\n";
        }
    }
    return 0;
}