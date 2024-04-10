#include<bits/stdc++.h>

using namespace std;

priority_queue <long long> Q;

const int MAXN = 2e5 + 10;

int a[MAXN];

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = n; i >= 1; i--)
        scanf("%d", &a[i]);
    /*
    for(int i = 1; i <= k; i++)
        Q.push(0);
    for(int i = n; i >= 1; i--){
        long long Nico = Q.top();
        Q.pop();
        Q.push(Nico - a[i]);
    }
    for(int i = 1; i < k; i++)
        Q.pop();
    cout<<-Q.top()<<endl;
    */
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans = max(ans, a[i] + a[2*k+1-i]);
    cout<<ans<<endl;
    return 0;
}