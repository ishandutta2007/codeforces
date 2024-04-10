#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int perm[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int pos[8][3],p[8][3];
int po[8],idk[3];
inline ll sq(int x){return 1LL*x*x;}
int main()
{
    int i,j,k;
    for(i=0;i<8;i++)for(j=0;j<3;j++)scanf("%d",&pos[i][j]);
    po[0]=1;
    for(i=1;i<8;i++)po[i]=po[i-1]*6;
    for(i=0;i<po[7];i++){
        memcpy(p,pos,sizeof(pos));
        for(j=0;j<8;j++){
            int ind=i/po[j]%6;
            for(k=0;k<3;k++)idk[k]=p[j][perm[ind][k]];
            memcpy(p[j],idk,sizeof(idk));
        }
        vector<ll>v;
        for(j=0;j<8;j++){
            for(k=j+1;k<8;k++){
                v.push_back(sq(p[j][0]-p[k][0])+sq(p[j][1]-p[k][1])+sq(p[j][2]-p[k][2]));
            }
        }
        sort(v.begin(),v.end());
        if(v[0]&&v[0]==v[11]&&v[0]*2==v[12]&&v[12]==v[23]&&v[0]*3==v[24]&&v[24]==v[27]){
            printf("YES\n");
            for(j=0;j<8;j++){
                for(k=0;k<3;k++)printf("%d ",p[j][k]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("NO\n");
}