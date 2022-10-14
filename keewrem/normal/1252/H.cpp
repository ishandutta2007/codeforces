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
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        cout << s <<"\n";


    }
    return 0;
}