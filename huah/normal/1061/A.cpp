#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    printf("%d\n",s/n+(s%n?1:0));
}