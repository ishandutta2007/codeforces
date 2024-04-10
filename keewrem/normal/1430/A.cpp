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
        if(N==7){cout << "0 0 1\n";continue;}
        bool k = 1;
        for(int i = 0; i*3 <= N; i++){
            if((N-i*3)%5==0){cout << i << " "<<(N-i*3)/5<<" 0\n";k = 0;break;}
        }
        if(k)cout << "-1\n";
    }
    return 0;
}