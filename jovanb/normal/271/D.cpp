#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

typedef long long ll;

const ll MOD = 1000000007;

string s;

int n;

int pr[10000];

set <pair <int, int>> seet;
map <char, bool> moze;

int pre[100000];
int prp[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int k;
    string nista;
    cin >> s;
    n = s.size();
    cin >> nista;
    for(int i=0; i<26; i++){
        moze[char(i+'a')] = nista[i]-'0';
    }
    cin >> k;
    if(moze[s[0]] == 0) pre[1] = 1;
    for(int i=1; i<n; i++){
        pre[i+1] = pre[i]+(1-moze[s[i]]);
    }
    pr[1]=41;
    for(int i=2; i<=n; i++){
        pr[i] = pr[i-1]*41;
        pr[i] %= MOD;
    }
    prp[1]=101;
    for(int i=2; i<=n; i++){
        prp[i] = prp[i-1]*101;
        prp[i] %= MOD;
    }
    for(int i=0; i<n; i++){
        int trenhes = 0;
        int drugihes = 0;
        for(int j=i; j<n; j++){
            if(pre[j+1]-pre[i] <= k){
                trenhes = (trenhes+pr[j-i+1]*(s[j]-'a'+1))%MOD;
                drugihes = (drugihes+prp[j-i+1]*(s[j]-'a'+1))%MOD;
                seet.insert({trenhes, drugihes});
            }
            else break;
        }
    }
    cout << seet.size();
    return 0;
}