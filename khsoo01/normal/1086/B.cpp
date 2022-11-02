#include<bits/stdc++.h>
using namespace std;

int n, s, ind[100005];

int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        ind[A]++;
        ind[B]++;
    }
    int T = 0;
    for(int i=1;i<=n;i++) {
        if(ind[i] == 1) T++;
    }
    printf("%.12f\n", (double)2*s/T);
}