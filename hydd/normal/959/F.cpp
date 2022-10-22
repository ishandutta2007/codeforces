#include<cstdio>
using namespace std;
const int Mod=1e9+7;
int n,q,x,y,a[110000],v[110000][25],cnt[110000],bin[110000];
bool check(int now,int x){
    for (int i=20;i>=0;i--){
        if (x&(1<<i)){
            if (!v[now][i]) return 0;
            x^=v[now][i];
        }
    }
    return (!x);
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        for (int j=0;j<=20;j++) v[i][j]=v[i-1][j];
        cnt[i]=cnt[i-1];
        for (int j=20;j>=0;j--)
            if (a[i]&(1<<j)){
                if (!v[i][j]){
					v[i][j]=a[i];
					cnt[i]++; break;
				} else a[i]^=v[i][j];
            }
    }
    bin[0]=1;
    for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2%Mod;
    while (q--){
        scanf("%d%d",&x,&y);
        if (!check(x,y)) puts("0");
        else printf("%d\n",bin[x-cnt[x]]);
    }
	return 0;
}