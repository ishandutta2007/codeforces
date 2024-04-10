#include<bits/stdc++.h>
using namespace std;
int n, x[1005];

char ipt[1005][1005], vow[7] = "aeiouy";

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    fgets(ipt[0], 201, stdin);
    for(int i=1;i<=n;i++) {
        fgets(ipt[i], 201, stdin);
        int tmp = 0;
        for(int j=0;j<200;j++) {
            for(int k=0;k<6;k++) {
                if(ipt[i][j] == vow[k]) {tmp++; break;}
            }
        }
        if(tmp != x[i]) {puts("NO"); return 0;}
    }
    puts("YES");
}