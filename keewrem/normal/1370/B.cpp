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

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int a;
        vi p; vi d;
        int c = 0;
        for(int i = 0; i< 2*N; i++){
            cin >> a;
            if(a&1)d.pb(i+1);
            else p.pb(i+1);
            if(d.size()==2 && c< N-1){
                cout << d[0]<<" "<< d[1] <<"\n";
                d.clear();
                c++;
            }
            if(p.size()==2 && c<N-1){
                cout << p[0]<<" "<< p[1] <<"\n";
                p.clear();
                c++;
            }

        }

    }
    return 0;
}