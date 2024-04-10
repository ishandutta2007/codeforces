#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int n;
int sol(int cur){
    int res = 0;
    fors(i,0,n){
        if(cur == s[i]-'0') ;
        else if(i == 0 || (s[i-1]-'0' == (cur ^1))) res++;
        cur ^= 1;
    }
    return res;
}
int main(){
    int T;cin>>T;
    while(T--){
        scanf("%d", &n);
        scanf("%s",s);
        int ans = min(sol(0), sol(1));
        printf("%d\n", ans);
    }
}