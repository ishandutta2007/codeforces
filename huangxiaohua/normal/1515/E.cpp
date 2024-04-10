#include <iostream>
#define f(x,y) for(x=y;x<=n;x++)
int64_t r,f[405][405]={{},{0,1}},i,j,n,M;main(){std::cin>>n>>M;f(i,2)f(j,1)f[i][j]=(f[i-2][j-1]+f[i-1][j]*2)*j%M,r+=f[n][j];
std::cout<<r%M;}