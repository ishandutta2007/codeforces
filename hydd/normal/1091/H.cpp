#include<cstdio>
#include<bitset>
using namespace std;
typedef long long ll;
bitset<200005> a,b[110];
int n,f,ans,tot;
int sg[200005],prime[200005],np[200005];

void init_prime(){
    for (int i=2;i<=200000;i++){
        if (!np[i]) prime[++tot]=i;
        for (int j=1;j<=tot&&i*prime[j]<=200000;j++){
            np[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}

int main(){
	scanf("%d%d",&n,&f);
	init_prime();
    for (int i=1;i<=tot;i++) a[prime[i]]=1;
    for (int i=1;i<=tot;i++){
        for (int j=i;j<=tot;j++){
            if (1ll*prime[i]*prime[j]>200000) break;
            a[prime[i]*prime[j]]=1;
        }
    }
    a[f]=0;
	b[0]=a;
    for (int i=1;i<=200000;i++){
        while (b[sg[i]][i]) sg[i]++;
        b[sg[i]]|=(a<<i);
    }
    int a,b,c;
    for (int i=1;i<=n;i++){
    	scanf("%d%d%d",&a,&b,&c);
        ans^=sg[b-a-1]; ans^=sg[c-b-1];
    }
    if (ans!=0) printf("Alice\nBob\n");
    else printf("Bob\nAlice\n");
    return 0;
}