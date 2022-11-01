#include<bits/stdc++.h>
using namespace std;
int up=(1<<17);
int main()
{
    int k;scanf("%d",&k);
    printf("3 3\n");
    printf("%d %d %d\n",k|up,k,k);
    printf("%d %d %d\n",up,up,k|up);
    printf("%d %d %d\n",up,up,k);
}
/*
100000
3 3
231072 100000 100000
131072 131072 231072
131072 131072 100000
*/