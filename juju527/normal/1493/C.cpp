#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int t[26];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n,k;
        n=read();k=read();
        scanf("%s",s+1);
        for(int i=0;i<26;i++)t[i]=0;
        for(int i=1;i<=n;i++)t[s[i]-'a']++;
        bool flag=1;
        for(int i=0;i<26;i++)if(t[i]%k){flag=0;break;}
        if(flag){
            for(int i=1;i<=n;i++)printf("%c",s[i]);
            printf("\n");
            continue;
        }
        for(int i=n;i>=1;i--){
            t[s[i]-'a']--;
            int cur=0;
            for(int c=0;c<26;c++)cur+=(k-(t[c]%k))%k;
            for(int c=s[i]-'a'+1;c<26;c++){
                cur-=(k-(t[c]%k))%k;t[c]++;cur+=(k-(t[c]%k))%k;
                if(n-i>=cur&&(n-i)%k==cur%k){
                    flag=1;
                    for(int j=1;j<i;j++)printf("%c",s[j]);
                    printf("%c",c+'a');
                    int pos=0,y=n-i-cur;
                    for(int j=i+1;j<=i+y;j++)printf("a");
                    for(int j=i+y+1;j<=n;j++){
                        while(t[pos]%k==0)pos++;
                        t[pos]++;
                        printf("%c",pos+'a');
                    }
                    printf("\n");
                    break;
                }
                cur-=(k-(t[c]%k))%k;t[c]--;cur+=(k-(t[c]%k))%k;
            }
            if(flag)break;
        }
        if(!flag)puts("-1");
    }
    return 0;
}