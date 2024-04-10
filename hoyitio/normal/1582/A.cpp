#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        ll a, b, c;
        cin>>a>>b>>c;
        c %= 2;
        int res = 3;
        if(c){
            if(b) res = 1;
        }
        else{
            res = 0;
            b %= 2;
            if(b) res = 2;
        }

        while(res && a){
            res--; a--;
        }
        if(a) res = (a&1);
        cout<<res<<endl;
    }
    return 0;
}

/*
1
1 1 2
*/