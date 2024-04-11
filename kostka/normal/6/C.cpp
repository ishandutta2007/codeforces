#include<cstdio>

int tab[1000007], sa[1000007], sb[1000007];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    sa[0] = tab[0];
    for(int i=1; i<n; i++)
        sa[i] = sa[i-1] + tab[i];
    sb[n-1] = tab[n-1];
    for(int i=n-2; i>=0; i--)
        sb[i] = sb[i+1] + tab[i];
    if(n==1)
    {
        printf("1 0\n");
        return 0;
    }
    for(int i=0; i<n; i++)
        if(sa[i] > sb[i])
        {
            printf("%d %d\n", i, n-i);
            return 0;
        }
}