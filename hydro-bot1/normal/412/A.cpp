// Hydro submission #6253dd9648f7830132793544@1649663383643
#include<bits/stdc++.h>
using namespace std;
char s[1000];
int n,k,i;
void l()
{
    for(i=n;i>k;i--) printf("LEFT\n");
}
void lp()
{
    for(i=k-1;i;i--)
    printf("LEFT\nPRINT %c\n",s[i]);
}
void r()
{
    for(i=1;i<k;i++) printf("RIGHT\n");
}
void rp()
{
    for(i=k+1;i<=n;i++)
    printf("RIGHT\nPRINT %c\n",s[i]);
}
int main()
{
    cin>>n>>k;
    scanf("%s",s+1);
    printf("PRINT %c\n",s[k]);
    if(2*k>n) rp(),l(),lp();
    else lp(),r(),rp();
    return 0;
}