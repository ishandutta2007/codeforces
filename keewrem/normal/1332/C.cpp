#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N,K;
string s;
int cnt[30];
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        cin >> s;
        int ans = 0;
        int m = 0;
        for(int i = 0; i < K/2; i++){
            m = 0;
            for(int j = 0; j < 30; j++)cnt[j]=0;
            for(int j = i; j < N; j+=K){
                cnt[s[j]-'a']++;
            }
            for(int j = K-1-i; j < N; j+=K){
                cnt[s[j]-'a']++;
            }
            for(int j = 0; j < 30; j++)m = max(cnt[j],m);
        //    cout << "m"<<m<<" ";
            ans+=2*(N/K)-m;
        }
        if(K%2){
            m = 0;
            for(int j = 0; j < 30; j++)cnt[j]=0;
            for(int i = K/2; i < N; i+=K){
                cnt[s[i]-'a']++;
            }
            for(int j = 0; j < 30; j++)m = max(cnt[j],m);
            ans+=(N/K)-m;

            //cout << "m"<<m<<" ";
        }
        cout << ans << "\n";
    }
    return 0;
}