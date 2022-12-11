#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[30],n,tot;
char ch[110000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&A[i]),tot+=A[i];
    if (tot%2==0){
        for (int now=tot;now>0;now-=2)
            if (tot%now==0){
                int flag=0; int len=tot/now;
                for (int i=1;i<=n;i++) if (A[i]%now) flag=1;
                if (flag) continue;
                int r=0;
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=A[i]/now;j++) ch[++r]='a'+i-1;
                for (int i=2;i<=now;i++)
                    for (int j=1;j<=len;j++)
                        ch[++r]=ch[(i-1)*len-j+1];
                printf("%d\n",now);
                for (int i=1;i<=tot;i++) putchar(ch[i]); putchar('\n');
                return 0;
            }
    } else {
        int where=0;
        for (int i=1;i<=n;i++) if (A[i]&1) where=i; 
        for (int now=tot;now>0;now-=2)
            if (tot%now==0){
                int len=tot/now; A[where]-=now; int flag=0;
                for (int i=1;i<=n;i++) if (A[i]%(now*2)) flag=1;
                if (flag){A[where]+=now; continue;}
                int r=0;
                for (int i=1;i<=now;i++){
                    ch[++r]='a'+where-1;
                    for (int j=1;j<=n;j++)
                        for (int k=1;k<=A[j]/(now*2);k++) ch[++r]='a'+j-1;
                    for (int j=n;j;j--)
                        for (int k=1;k<=A[j]/(now*2);k++) ch[++r]='a'+j-1;
                }
                printf("%d\n",now);
                for (int i=1;i<=tot;i++) putchar(ch[i]); putchar('\n');
                return 0;
            }
    }
    printf("0\n");
    for (int i=1;i<=n;i++)
        for (int j=1;j<=A[i];j++) putchar('a'+i-1); 
    cout<<endl;
    return 0;
}