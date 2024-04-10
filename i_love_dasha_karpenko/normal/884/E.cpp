#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = (1<<15)+7;
int cmp[N];
int ptr = 0;
int cnt = 0;
void decrypt(int pos){
    char ch;
    cin>>ch;
    int num;
    if ('0'<=ch && ch<='9')
        num = ch-'0';
    else num = ch-'A'+10;
    for(int j = pos+3;j>=pos;--j){
        if (num&1){
            if (cmp[j]==0) {
                cmp[j] = ++ptr,++cnt;
            }
        }
        else cmp[j] = 0;
        num = num>>1;
    }
}
int P[N],M[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    return 1;
}
void norm(int m){
    ptr = 0;

    for(int j = 0;j<m;++j) {
        if (cmp[j]==0)
            continue;
        M[cmp[j]] = 1;
    }
    for(int i = 1;i<=m*2;++i){
        M[i] += M[i-1];
    }
    for(int j = 0;j<m;++j){
        if (cmp[j]==0)
            continue;
        cmp[j] = M[cmp[j]];
        P[cmp[j]] = cmp[j];
        ptr = max(ptr,cmp[j]);
    }
    for(int i = 0;i<=m*2;++i)
        M[i] = 0;
    for(int j = 1;j<m;++j){
        if (cmp[j-1]>0 && cmp[j]>0){
            cnt-=unite(cmp[j-1],cmp[j]);
        }
    }
    for(int j = 0;j<m;++j){
        cmp[j] = F(cmp[j]);
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<m;j+=4){
            decrypt(j);
        }
        norm(m);
    }
    cout<<cnt<<endl;
    return 0;
}