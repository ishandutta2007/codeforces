#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        for(int i = 2*n; i < 4*n; i += 2) {
            printf("%d", i);
            if(i+2 == 4*n) printf("\n");
            else printf(" ");
        }
    }
}