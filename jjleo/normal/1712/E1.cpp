#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

typedef long long ll;

int t, l, r;
vector<int> v[maxn];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &l, &r);
        ll ans = 1ll * (r - l + 1) * (r - l + 1 - 1) * (r - l + 1 - 2) / 6;
        for(int i = 0;i < maxn;i++) v[i].clear();
        for(int i = l;i <= r;i++){
            for(int j = i;j <= r * 2;j += i) v[j].push_back(i);
        }
        for(int i = l;i <= r;i++){
            vector<int> a = v[i * 2];
            int pos = 1;
            for(int j = 1;j < a.size() && a[j] < i;j++){
                while(pos && a[pos - 1] + a[j] + i > i * 2) pos--;
                if(j == pos) pos++;
                else ans -= j - pos;
            }
            a = v[i];
            pos = 1;
            for(int j = 1;j < a.size() && a[j] < i;j++){
                while(pos && a[pos - 1] + a[j] + i > i * 2) pos--;
                if(j == pos) pos++;
                else ans += j - pos;
            }
            int cnt = 0;
            for(int j = 0;j < a.size();j++) cnt += a[j] < i;
            ans -= 1ll * cnt * (cnt - 1) / 2;
        }
        printf("%lld\n", ans);
    }
}