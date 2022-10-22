#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
const int maxn = 2e5 +5 ;
int a[maxn];
int suf[maxn];
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        fors(i,1,n+1) scanf("%d", &a[i]);
        suf[n] = 1;
        suf[n+1] = 1;
        a[n+1] = 1e9 + 7;
        for(int i = n-1; i > 0; --i){
            if(a[i] <= a[i+1]) suf[i] = suf[i+1];
            else suf[i] = 0;
        }
        int cur = a[1];
        int res = 0;
        int flag = 0;
        if(suf[1]) flag = 1;
        if(suf[2]) flag = 1;
        fors(i,2,n+1){
            //cout<<"i:"<<i-1<<" cur:"<<cur<<" res:"<<res<<endl;
            if(cur >= a[i]){
                if(res > a[i]){
                    break;
                }else{
                    cur = a[i]-res;
                    //cout<<"i:"<<i<<" cur:"<<cur<<" res:"<<res<<endl;
                }
            }else{
                if(cur + res > a[i]){//cur should down
                    //break;
                    if(a[i] < res) break;
                    cur = a[i] - res;
                }else{
                    res = a[i] - cur;
                }
            }
            if(a[i+1] >= res && suf[i+1]) {flag = 1; break;};
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
}