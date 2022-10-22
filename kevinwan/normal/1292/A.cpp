#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
inline ll gcd(ll a,ll b){while(b)a%=b,swap(a,b);return a;}
bool ded[2][mn];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int hail=0;
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        if(ded[a][b]){
            hail-=ded[a^1][b-1];
            hail-=ded[a^1][b];
            hail-=ded[a^1][b+1];
            ded[a][b]=0;
        }
        else{
            hail+=ded[a^1][b-1];
            hail+=ded[a^1][b];
            hail+=ded[a^1][b+1];
            ded[a][b]=1;
        }
        if(hail)printf("No\n");
        else printf("Yes\n");
    }
}