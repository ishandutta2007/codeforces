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
int N,K,a;

bool check(int a, int b, int c){
    return ((a+b) > (a+b+c-1)/2) && ((b+c) > (a+b+c-1)/2);
}

int sas[100010];
int main(){
    cin >> T;
    while(T--){
        cin >> N>>K;
        bool ses = 0;
        for(int i = 0; i < N; i++){
            cin >> a; if(a == K) ses = 1;
            if(a >= K)sas[i] = 1;
            else sas[i] = 0;
        }
        int l = 0, c = 0; bool sos = 0;
        for(int i = 0; i < N; i++){
            c+= sas[i]; l++;
            if(c > l/2 && l > 1)sos = 1;
            if(c < (l+1)/2){l = 0; c = 0;}
        }
        if(N == 1)sos = 1;
        if(sos & ses)cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}