#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int bit[100005];
int fr[100005];
int bk[100005];
int n;
int niz[100005];
int type[100005];
int ima[100005];

void addbit(int x, int val){
    while(x <= 100005){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

int getbit(int x){
    int res=0;
    while(x > 0){
        res = max(res, bit[x]);
        x -= x & -x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    int mx=1;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        fr[i] = 1+getbit(niz[i]-1);
        addbit(niz[i], fr[i]);
    }
    for(int i=1; i<=100000; i++){
        bit[i] = 0;
    }
    for(int i=n; i>=1; i--){
        bk[i] = 1+getbit(100001-niz[i]);
        addbit(100002-niz[i], bk[i]);
        mx = max(mx, fr[i]+bk[i]);
    }
    for(int i=1; i<=n; i++){
        if(fr[i]+bk[i] != mx) type[i] = 1;
        else{
            ima[fr[i]]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(type[i] == 1) continue;
        if(ima[fr[i]] > 1 && fr[i]+bk[i] == mx) type[i] = 2;
        else type[i] = 3;
    }
    for(int i=1; i<=n; i++) cout << type[i];
    return 0;
}