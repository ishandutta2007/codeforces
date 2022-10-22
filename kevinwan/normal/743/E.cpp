#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=3e5+10;
vector<int> p[8];
int nxt[1010][8][140];
int b[8];
int perm[8];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[x-1].push_back(i);
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<8;j++){
            int tar=lower_bound(p[j].begin(),p[j].end(),i)-p[j].begin()-1;
            nxt[i][j][0]=i;
            for(int k=1;k<=128;k++){
                if(tar+k<p[j].size())nxt[i][j][k]=p[j][tar+k]+1;
                else nxt[i][j][k]=n+1;
            }
        }
    }
    iota(perm,perm+8,0);
    int ans=0;
    do{
        for(int i=0;i<256;i++){
            for(int j=0;j<8;j++)b[j]=(i>>j)&1;
            int cur=-1;
            for(int j=64;j;j>>=1){
                int tri=cur+j;
                int v=0;
                bool gud=1;
                for(int x:perm){
                    if(v==n+1){
                        gud=0;
                        break;
                    }
                    v=nxt[v][x][tri+b[x]];
                }
                if(v==n+1)gud=0;
                if(gud)cur+=j;
            }
            ans=max(ans,8*cur+__builtin_popcount(i));
        }
    }while(next_permutation(perm,perm+8));
    printf("%d",ans);
}