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
        if(N%2 == 0){
            if(N==2){cout << "Ashishgup\n"; continue;}
            if(N%4 == 0){
                bool k = 1;
                for(int i = 4; i < 1000000007; i*=2)if(i==N){cout << "FastestFinger\n";k =0; }
                if(k)cout << "Ashishgup\n"; continue;
            }
            bool k = 1;
            for(int i = 3; i*i<=N; i+=2)if(N%i==0 && i!=N){cout << "Ashishgup\n"; k = 0; break;}
            if(k)cout << "FastestFinger\n"; continue;
        }
        if(N==1)cout << "FastestFinger\n";
        else cout << "Ashishgup\n";

    }
    return 0;
}