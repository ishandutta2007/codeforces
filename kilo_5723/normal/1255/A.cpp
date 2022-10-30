#include<iostream>
#include<cstdio>
using namespace std;
int _abs(int n){ return n<0?-n:n; }
int solve(int n){
    int ans=0;
    ans=n/5; n%=5;
    switch (n){
        case 4: ans+=2; break;
        case 3: ans+=2; break;
        case 2: ans+=1; break;
        case 1: ans+=1; break;
    }
    return ans;
}
int main(){
    int tt;
    int a,b;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d %d",&a,&b);
        printf("%d\n",solve(_abs(b-a)));
    }
    return 0;
}