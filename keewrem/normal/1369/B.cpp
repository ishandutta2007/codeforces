#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
#include<bits/stdc++.h>
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        string s;
        cin >> N >> s;
        int z = 0, u = 0;
        for(auto x: s){if(x=='0')z++; else break;}
        for(int i = N-1; i>=0; i--){if(s[i]=='1')u++; else break;}
        if(z+u!=N)z++;
        while(z--)cout << "0"; while(u--)cout <<"1"; cout <<"\n";
    }
    return 0;
}