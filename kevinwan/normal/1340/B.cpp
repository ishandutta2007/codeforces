#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e3+10;
const ll mod=1e9+7;
int d[10]={0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
char s[10];
int v[mn],dis[mn][10];
bool pos[mn][mn];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int x=0;
        scanf("%s",s);
        for(int j=0;j<7;j++)x|=(s[j]-'0')<<(6-j);
        v[i]=x;
    }
    for(int i=0;i<n;i++)for(int j=0;j<10;j++){
        if((v[i]&d[j])!=v[i])dis[i][j]=mn;
        else dis[i][j]=__builtin_popcount(d[j]^v[i]);
    }
    pos[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            for(int l=0;l<10;l++)if(dis[i][l]<=j){
                pos[i][j]|=pos[i+1][j-dis[i][l]];
            }
        }
    }
    if(!pos[0][k]){
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=9;j>=0;j--){
            if(k-dis[i][j]>=0&&pos[i+1][k-dis[i][j]]){
                printf("%d",j);
                k-=dis[i][j];
                break;
            }
        }
    }
}