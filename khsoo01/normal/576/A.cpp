#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[1005];
bool is_prime[1005];

int main()
{
    int i,j,tmp;
    scanf("%d",&n);
    for(i=2;i<=n;i++) {
        if(!is_prime[i]) {
            for(j=2*i;j<=n;j+=i) {
                is_prime[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++) {
        if(!is_prime[i]) {
            tmp=i;
            while(tmp<=n) {
                cnt++;
                tmp*=i;
            }
        }
    }
    printf("%d\n",cnt);
    for(i=2;i<=n;i++) {
        if(!is_prime[i]) {
            tmp=i;
            while(tmp<=n) {
                printf("%d ",tmp);
                tmp*=i;
            }
        }
    }
}