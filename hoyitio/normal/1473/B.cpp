#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        string s, t; cin>>s>>t;
        int a = s.size();
        int b = t.size();
        int g = __gcd(a,b);
        int len = a*b/g;
        string ss = "", tt = "";
        fors(i,0,len/a) ss += s;
        fors(i,0,len/b) tt += t;
        if(ss == tt) cout<<ss<<endl;
        else cout<<-1<<endl;
    }
	return 0;
}