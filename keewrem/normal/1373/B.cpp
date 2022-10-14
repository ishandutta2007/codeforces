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
int N;

string s;

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        N = s.size();
        int c  = 0;
        for(auto x: s)c+=x-'0';
        c = min(c,N-c);
        if(c&1)cout << "DA\n";
        else cout <<"NET\n";
    }
    return 0;
}