#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int a[MAXN];
int L[MAXN], R[MAXN];

void work(){
    /*
    stack<int> Q;
    Q.push(1);
    L[1] = 1;
    for(int i = 2; i <= n; i++){
        while(!Q.empty() && a[Q.top()] < a[i])
            Q.pop();
        if (!Q.empty()){
            L[i] = Q.top()+1;
            Q.push(i);
        }
        else{
            L[i] = 1;
            Q.push(i);
        }
    }
    stack<int> P;
    Q.push(n);
    R[n] = n;
    for(int i = n - 1; i >= 1; i--){
        while(!P.empty() && a[P.top()] < a[i])
            P.pop();
        if (!P.empty()){
            R[i] = P.top()+1;
            P.push(i);
        }
        else{
            R[i] = n;
            P.push(i);
        }
    }*/
    L[1] = 1;
    for(int i = 2; i <= n; i++){
        int j = i - 1;
        while(j != 1 && a[j] <= a[i])
            j = L[j];
        L[i] = j;
    //  while (a[L[i]] >= a[i] && L[i] < i)
    //      L[i]++;
    }
    R[n] = n;
    for(int i = n - 1; i >= 1; i--){
        int j = i + 1;
        while(j != n && a[j] < a[i])
            j = R[j];
        R[i] = j;
    //  while (a[R[i]] >= a[i] && R[i] > i)
    //      R[i]--;
    }
    for(int i = 1; i <= n; i++){
        while (a[L[i]] > a[i] && L[i] < i)
            L[i]++;
        while (a[R[i]] >= a[i] && R[i] > i)
            R[i]--;
    }
}

int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
        a[i] = abs(a[i+1] - a[i]);
    n--;
    work();
//  for(int i = 1; i <= n; i++)
//      cout<<a[i]<<' ';cout<<endl;
//  for(int i = 1; i <= n; i++)
//      cout<<L[i]<<' ';cout<<endl;
//  for(int i = 1; i <= n; i++)
//      cout<<R[i]<<' ';cout<<endl;
    while(m--){
        int l,r;
        scanf("%d%d", &l, &r);
        long long ans = 0;
        r--;
        for(int i = l; i <= r; i++){
            ans += (long long)(min(R[i], r) - i + 1) * (i - max(L[i], l) + 1)* a[i];
        //  cout<<i<<' '<<L[i]<<' '<<R[i]<<' '<<(long long)((min(R[i], r) - i + 1) * (i - max(L[i], l) + 1)) * a[i]<<endl;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}