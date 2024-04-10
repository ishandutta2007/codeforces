#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void work(){
    ll s,n,k;
    cin>>s>>n>>k;
    if(s==k){
        puts("YES");
        return;
    }
    if(s<n/k*2*k+n%k){
        puts("YES");
        return;
    }
    puts("NO");
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
2
9 5 2
6 4 5
*/