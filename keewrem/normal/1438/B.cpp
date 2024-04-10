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
int a[1001];
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        bool k = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                if(k && a[i] == a[j]){cout << "YES\n";k=0;}
            }
        }
        if(k)cout <<"NO\n";
    }
    return 0;
}