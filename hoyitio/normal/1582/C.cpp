#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5+5;
char s[maxn];
int n;
void init(){
    scanf("%d", &n);
    scanf("%s",s+1);
}
int check(char ch){
    int l = 1, r = n;
    int res = 0;
    while(l <= r){
        if(s[l]==s[r]){l++;r--; continue;}
        if(s[l]!=ch && s[r]!=ch) return n;
        res++;
        if(s[l]==ch) l++;
        else r--;
    }return res;
}
void sol(){
    int ans = n;
    for(char ch = 'a'; ch <= 'z'; ++ch) ans = min(ans, check(ch));
    if(ans == n) ans = -1;
    cout<<ans<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        init(); sol();
    }
    return 0;
}