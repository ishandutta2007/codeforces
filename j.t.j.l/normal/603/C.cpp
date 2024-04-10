#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN];

int work(int x){
    if (x < 4)
        return (x & 1);
    if (x == 4)
        return 2;
    if (x & 1)
        return 0;
    else{
        int p = work(x / 2);
        return p == 1 ? 2 : 1;
    }
}

int main(){
    int n, k;
//  for(int i = 0; i <= 10; i++)
//      cout<<work(i)<<' '<<i<<endl;
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    if (k & 1){
        for(int i = 1; i <= n; i++){
            ans ^= work(a[i]);
        }
    }
    else{
        for(int i = 1; i <= n; i++)
            if (a[i] <= 2)
                ans ^= a[i];
            else
                ans ^= ((a[i] & 1) ^ 1);
    }
    if (ans)
        puts("Kevin");
    else
        puts("Nicky");
    return 0;
}