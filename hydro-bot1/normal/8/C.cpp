// Hydro submission #625a16d3cc64917dc4671c8b@1650071251936
#include <math.h>
#include <stdio.h>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
inline bol _min(ullt&a,ullt b){return(b<a)?a=b,true:false;}
inline ullt time(int x1,int y1,int x2,int y2){return(llt)(x1-x2)*(x1-x2)+(llt)(y1-y2)*(y1-y2);}
inline uint hash(uint a,uint b){return a*25+b;}
ullt cost[16777220],T[30][30];uint from[16777220],way[16777220];
uint LOG[37];
int X[30],Y[30];
voi get(uint S)
{
    if(!S){putchar('0');return;}
    get(from[S]);
    if(way[S]/25==way[S]%25)printf(" %d 0",way[S]/25+1);else printf(" %d %d 0",way[S]/25+1,way[S]%25+1);
}
int main()
{
    uint n;register uint p,q;
    scanf("%d%d%u",X,Y,&n);for(uint i=1;i<=n;i++)scanf("%d%d",X+i,Y+i);
    for(uint i=0;i<=n;i++)for(uint j=0;j<=n;j++)T[i][j]=time(X[i],Y[i],X[j],Y[j]);
    for(uint i=1;i<=n;i++)for(uint j=1;j<=n;j++)T[i][j]+=T[0][i]+T[j][0];
    const uint tp=1<<n;
    for(uint i=0;i<=30;i++)LOG[(1u<<i)%37]=i;
    for(register uint S=1;S<tp;S++)
    {
        p=S&-S;cost[S]=1145141919810llu;
        for(uint S2=S;S2;S2-=q)
        {
            q=S2&-S2;
            if(_min(cost[S],cost[S^(p|q)]+T[LOG[p%37]+1][LOG[q%37]+1]))
                from[S]=S^(p|q),way[S]=hash(LOG[p%37],LOG[q%37]);
        }
    }
    printf("%llu\n",cost[tp-1]),get(tp-1),putchar('\n');
    return 0;
}