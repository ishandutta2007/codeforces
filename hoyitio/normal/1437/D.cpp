#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int dep[maxn];
int main(){
    int T; cin>>T;
    while(T--){
        int ans = 1;
        int n; scanf("%d", &n);
        fors(i,0,n+1) dep[i] = 0;
        fors(i,0,n) scanf("%d", &a[i]);
        dep[0] = 1;
        int cur = 1;
        int cd = 1;
        fors(i,1,n){
           // scanf("%d", &a[i]);
            if(a[i] < a[i-1]) {
                if(dep[cd-1] > cur) {cur++; dep[cd]++;}
                else{
                    cd++; ans++; cur = 1; dep[cd] = 1;
                }
            }else {
                dep[cd]++;
            }
        }
        printf("%d\n", ans);
    }
}