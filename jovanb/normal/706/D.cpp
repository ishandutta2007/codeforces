#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int trie[3000005];
int nxt[3000005][2];

int cnt = 0;

void add(int x){
    int tren=0;
    int bt = (1 << 30);
    while(bt){
        int ima = 0;
        if(bt & x) ima = 1;
        if(!nxt[tren][ima]) nxt[tren][ima] = ++cnt;
        tren = nxt[tren][ima];
        trie[tren]++;
        bt >>= 1;
    }
}

void ers(int x){
    int tren=0;
    int bt = (1 << 30);
    while(bt){
        int ima = bt & x;
        if(bt & x) ima = 1;
        tren = nxt[tren][ima];
        trie[tren]--;
        bt >>= 1;
    }
}

int kveri(int x){
    int tren=0;
    int bt = (1 << 30);
    int res=0;
    while(bt){
        int ima = 0;
        if(bt & x) ima = 1;
        int a = nxt[tren][1-ima];
        int b = nxt[tren][ima];
        if(trie[a]){
            res += bt*(1-ima);
            tren = a;
        }
        else{
            res += bt*ima;
            tren = b;
        }
        bt >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int q;
    cin >> q;
    while(q--){
        char a;
        int x;
        cin >> a >> x;
        if(a == '+') add(x);
        if(a == '-') ers(x);
        if(a == '?') {
            cout << max(x, (x ^ kveri(x))) << "\n";
        }
    }
    return 0;
}