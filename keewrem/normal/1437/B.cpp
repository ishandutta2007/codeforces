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
        string s;
        cin >> s;
        int c = 0, cc = 0;
        for(int i = 1; i < N; i++)if(s[i]==s[i+1]){
            if(s[i]=='0')c++;
            else cc++;
        }
        cout << max(c,cc)<<"\n";
    }
    return 0;
}