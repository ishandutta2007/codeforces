#include <bits/stdc++.h>
using namespace std;
int N,M,P;
int a[1000000];
int b[1000000];
int main(){
    cin >> N >> M >> P;
    for(int i = 0; i < N; i++)scanf("%d", &a[i]);
    for(int i = 0; i < M; i++)scanf("%d", &b[i]);
    for(int i = 0; i < N; i++)a[i]%=P;
    for(int i = 0; i < M; i++)b[i]%=P;
    int aa,bb;
    for(int i = 0; i < N;i++)if(a[i]!=0)aa=i;
    for(int i = 0; i < M;i++)if(b[i]!=0)bb=i;
    cout << aa+bb<<"\n";
    return 0;
}