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
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        bool k = 1;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]!=s[0])k = 0;
        }
        if(k){cout << s << "\n"; continue;}
        string res = "";
        for(int i = 0 ; i < s.size(); i++)res+="01";
        cout << res << "\n";
    }
    return 0;
}