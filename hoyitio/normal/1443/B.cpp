#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
const int maxn = 1e5 +5 ;
char s[maxn];
int x, y;


int main(){
    int T; cin>>T;
    while(T--){
        scanf("%d%d", &x, &y);
        scanf("%s", s+1);
        int n = strlen(s+1);
        int cur = 1;
        int flag = 0;
        int cnt = 0;
        int ans = 0;
        if(s[1] == '1') flag =1;
        fors(i,2,n+2){
            if(s[i] == s[i-1]){
                cur++;
            }else{
                // if(s[i-1] == '0'){
                //     cout<<"cur:"<<cur<<endl;
                // }
                if(s[i-1] == '1') cnt++;
                if(i <= n && s[i-1] == '0' && flag && cur*y < x) {
                   // cout<<"ans:"<<ans<<endl;
                    ans += cur*y, cnt--;
                }
                cur = 1;
            }
            if(s[i] == '1') flag = 1;
        }
        //cout<<"cnt:"<<cnt<<endl;
        ans += cnt*x;
        printf("%d\n", ans);
    }
}