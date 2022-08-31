// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int T,n,m;
char a[N][N],b[N][N];
int x[26][2][2];
template<class T>void chkmin(T &a,T b){
    if(b<a){
        a=b;
    }
}
template<class T>void chkmax(T &a,T b){
    if(b>a){
        a=b;
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%s",a[i]+1);
    }
    for(int i=0;i<26;++i){
        x[i][0][0]=n+1;
        x[i][0][1]=0;
        x[i][1][0]=m+1;
        x[i][1][1]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(isalpha(a[i][j])){
                int c=a[i][j]-'a';
                chkmin(x[c][0][0],i);
                chkmax(x[c][0][1],i);
                chkmin(x[c][1][0],j);
                chkmax(x[c][1][1],j);
            }
            b[i][j]='.';
        }
    }
    int last=-1;
    for(int c=0;c<26;++c){
        if(x[c][0][1]){
            if(x[c][0][0]!=x[c][0][1]&&x[c][1][0]!=x[c][1][1]){
                puts("NO");
                return;
            }
            while(++last!=c){
                x[last][0][0]=x[c][0][0];
                x[last][0][1]=x[c][0][1];
                x[last][1][0]=x[c][1][0];
                x[last][1][1]=x[c][1][1];
            }
            for(int i=x[c][0][0];i<=x[c][0][1];++i){
                for(int j=x[c][1][0];j<=x[c][1][1];++j){
                    b[i][j]=c+'a';
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]!=b[i][j]){
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
    printf("%d\n",last+1);
    for(int i=0;i<=last;++i){
        printf("%d %d %d %d\n",x[i][0][0],x[i][1][0],x[i][0][1],x[i][1][1]);
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}