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
const int emme = 2010;
int N,K;
map<string,int> m;
string sos[emme];
int dp[emme][emme];
string x;
int added_sticks[emme][emme];
bool check(string a, string b){
    for(int i  =0 ; i < a.size(); i++){
        if(a[i] == '1' && b[i] == '0')return 1;
    }
    return 0;
}
int cnt(string a,string b){
    int c = 0;
    for(int i  =0 ; i < a.size(); i++){
        if(a[i] == '1' && b[i] == '0')c++;
    }
    return c;
}
vector<string> sus = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int main(){
    cin >> N >> K;
    for(int i = 0 ; i < N; i ++)cin >> sos[i];
    for(int i = 0; i <= N; i++)for(int j = 0; j<= K; j++)dp[i][j] =-1;
    m["1110111"] = 0;
    m["0010010"] = 1;
    m["1011101"] = 2;
    m["1011011"] = 3;
    m["0111010"] = 4;
    m["1101011"] = 5;
    m["1101111"] = 6;
    m["1010010"] = 7;
    m["1111111"] = 8;
    m["1111011"] = 9;
    int q; dp[N][0] = 0;
    for(int i = N-1; i>=0; i--){
        for(int k = 0; k < 10; k++){
            if(check(sos[i],sus[k])) continue;
            q = cnt(sus[k],sos[i]);
            for(int j = 0; j <= K; j++){

                if(j >= q && dp[i+1][j-q]!=-1){
                    dp[i][j] = k;
                    added_sticks[i][j] = q;
                }
            }
        }
    }
    if(dp[0][K] == -1){
        cout << -1; return 0;
    }
    int z = K;
    string s = "";
    for(int i = 0; i<N; i++){
        s+=(char)dp[i][z]+'0';
        z -= added_sticks[i][z];
    }
//    reverse(s.begin(),s.end());
    cout << s;
    //cout << cnt("1111111","0000000");
    return 0;
}