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
        ll c=0,cc=0,ans=0;

        for(int i = 0; i < N; i++){
            if(s[i]=='-'){ans++;
            if(i==0){
                if(s[N-1]!='-')ans++;
            }else{
                if(s[i-1]!='-')ans++;
            }
            }
            if(s[i]=='<')c++;
            if(s[i]=='>')cc++;

        }
        if(c==0 || cc==0)ans=N;
        cout << ans << "\n";
    }
    return 0;
}