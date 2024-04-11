#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef pair<long long,int> pi;

const int mod1 = 1e9 + 513;
const int mod2 = 1e9 + 531;

int pow1[200005], pow2[200005];
char S[200005], T[200005];
int lS, lT;

int HS1[26][200005], HS2[26][200005];
int HT1[26][200005], HT2[26][200005];

pi v1[26], v2[26];

void init(){
    scanf("%d %d %s %s",&lS,&lT,S,T);
    pow1[0] = pow2[0] = 1;
    for (int i=1; i<=200000; i++) {
        pow1[i] = pow1[i-1] << 1;
        pow1[i] %= mod1;
        pow2[i] = pow2[i-1] << 1;
        pow2[i] %= mod2;
    }
    for (int i=0; S[i]; i++) {
        for (int j=0; j<26; j++) {
            char t = j + 'a';
            if(i) HS1[j][i] = HS1[j][i-1] << 1;
            if(t == S[i]) HS1[j][i] |= 1;
            if(i) HS2[j][i] = HS2[j][i-1] << 1;
            if(t == S[i]) HS2[j][i] |= 1;
            HS1[j][i] %= mod1;
            HS2[j][i] %= mod2;
        }
    }
    for (int i=0; T[i]; i++) {
        for (int j=0; j<26; j++) {
            char t = j + 'a';
            if(i) HT1[j][i] = HT1[j][i-1] << 1;
            if(t == T[i]) HT1[j][i] |= 1;
            if(i) HT2[j][i] = HT2[j][i-1] << 1;
            if(t == T[i]) HT2[j][i] |= 1;
            HT1[j][i] %= mod1;
            HT2[j][i] %= mod2;
        }
    }
    for (int i=0; i<26; i++) {
        v1[i] = pi(1ll * HT1[i][lT-1] * mod2 + HT2[i][lT-1],i);
    }
    sort(v1,v1+26);
}

bool match(int t){
    for (int i=0; i<26; i++) {
        long long h1 = HS1[i][t + lT - 1];
        if(t != 0) h1 -= 1ll * pow1[lT] * HS1[i][t - 1];
        long long h2 = HS2[i][t + lT - 1];
        if(t != 0) h2 -= 1ll * pow2[lT] * HS2[i][t - 1];
        h1 %= mod1;
        h2 %= mod2;
        h1 += mod1;
        h2 += mod2;
        h1 %= mod1;
        h2 %= mod2;
        v2[i] = pi(1ll * h1 * mod2 + h2, i);
    }
    sort(v2,v2+26);
    map<int,int> mp;
    for (int i=0; i<26; i++) {
        if(v1[i].first == v2[i].first){
            if(v1[i].first == 0) continue;
            int t = v1[i].second;
            int u = v2[i].second;
            if(t == u){
                if(mp.find(t) != mp.end() && mp[t] != u) return 0;
                mp[t] = u;
                continue;
            }
            if(t > u) swap(t,u);
            if(mp.find(u) != mp.end() && mp[u] != t) return 0;
            if(mp.find(t) != mp.end() && mp[t] != u) return 0;
            mp[t] = u;
            mp[u] = t;
        }
        else return 0;
    }
    return 1;
}

int main(){
    init();
    vector<int> v;
    for (int i=0; i<=lS - lT; i++) {
        if(match(i)) v.push_back(i);
    }
    printf("%d\n",(int)v.size());
    for (auto &i : v){
        printf("%d ",i+1);
}
}