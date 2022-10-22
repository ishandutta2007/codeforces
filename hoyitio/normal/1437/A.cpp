#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int l, r;scanf("%d%d", &l, &r);
        if(2*l > r) puts("YES");
        else puts("NO");
    }
}