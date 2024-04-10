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

int T = 1;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        vi cnt(N+1,0);
        int a;
        for(int i = 0; i < N; i++){
            cin >> v[i];
            cnt[v[i]]++;
        }
        int ans = 0;
        for(int i = 0; i <= N; i++)if(cnt[i]*2-1>N)ans = 1;
        if(ans){cout << "-1\n"; continue;}
        vector<pii> sos;
        int l = 0;
        for(int i = 0; i < N-1; i++){
            if(v[i] == v[i+1]){sos.pb({v[l],v[i]}); l = i;}
        }
        sos.pb({v[l],v[N-1]});
        vi ecnt(N+1,0),scnt(N+1,0);
        for(auto x: sos){
        //    cout << x.fi << " "<<x.se <<"\n";
        }
        for(auto x: sos)scnt[x.fi]++;
        for(auto x: sos)scnt[x.se]++;
        int m = 0;
        for(int i = 0; i <= N; i++){
            m = max(m,scnt[i]+ecnt[i]-1-(int)sos.size());
        }
        cout << (int)sos.size()-1+m<<"\n";

    }
    return 0;
}