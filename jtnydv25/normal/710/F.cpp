#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int base = 541, mod = 1e9 + 7;
const int N = 3e5 + 10;
int pw[N], lengths[N], sz;
char s[N];
bool present[N];
inline void add(int l){
    if(!present[l]) lengths[sz++] = l;
    present[l] = 1; 
}
set<int> hashes;
int H[N];
int main(){
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * 1ll * base % mod;
    int q, type;
    scanf("%d", &(q));
    while(q--){
        scanf("%d%s", &type, s + 1);
        int l = 1; H[0] = 0;
        
        for(;s[l] ; l++){
            H[l] = (H[l - 1] * 1ll * base + s[l] - 'a' + 1) % mod;
        }
        l--;
        if(type == 1){
            add(l);
            hashes.insert(H[l]);
        }
        else if(type == 2) hashes.erase(H[l]);
        else{
            int ans = 0;
            for(int j = 0; j < sz; j++){
                for(int i = 1; i + lengths[j] - 1 <= l; i++){
                    int hsh = (H[i + lengths[j] - 1] - H[i - 1] * 1ll * pw[lengths[j]]) % mod;
                    if(hsh < 0) hsh += mod;
                    if(hashes.count(hsh)) ans++;
                }
            }
            printf("%d\n", ans);
            fflush(stdout);
        }
    }
}