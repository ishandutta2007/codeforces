#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char s[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,d=0;scanf("%d%d",&n,&x);
        for(int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            if(u==x||v==x) d++;
        }
        if(d==1||n==1) printf("Ayush\n");
        else printf(((n-2)&1)?"Ashish\n":"Ayush\n");
    }
}