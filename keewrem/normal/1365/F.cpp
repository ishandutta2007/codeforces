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
        vi a(N),b(N);
        for(int i = 0; i < N; i++)cin >>a[i];
        for(int i = 0; i < N; i++)cin >>b[i];
        bool k = 0;
        vector<pii> aa,bb;
        for(int i = 0; i < (N+1)/2; i++){
            if(a[i]<a[N-i-1])swap(a[i],a[N-i-1]);
            if(b[i]<b[N-i-1])swap(b[i],b[N-i-1]);
            aa.pb({a[i],a[N-i-1]});
            bb.pb({b[i],b[N-i-1]});
        }
        sort(aa.begin(),aa.end());
        sort(bb.begin(),bb.end());
        for(int i = 0; i < aa.size(); i++){
            if(aa[i]!=bb[i])k = 1;
        }
        if(k)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}