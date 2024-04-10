// Hydro submission #62b6c85fa5aaa85be1dff062@1656146015815
#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Begin;
const int max_n=502;
inline int read(){
    int x=0;bool w=0;char c=getchar();
    while(c<'0' || c>'9') w|=c=='-',c=getchar();
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void write(int x){
    putchar(x==2?'B':'W');
}
inline int reads(){
    char c=getchar();
    while(c!='B' && c!='W' && c!='.') c=getchar();
    if(c=='B') return 2;
    if(c=='W') return 3;
    return 0;
}

int n,m,cntr;
int a[max_n][max_n],ans[max_n][max_n];

int Tmp[max_n][max_n];
inline void rotate(){
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            Tmp[i][j]=a[i][j];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            a[j][n-i+1]=Tmp[i][j];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            Tmp[i][j]=ans[i][j];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            ans[j][n-i+1]=Tmp[i][j];
    swap(n,m),++cntr;
}
inline void clear(){
    cntr=0;
    for(register int i=0;i<=n;++i)
        for(register int j=0;j<=m;++j)
            a[i][j]=ans[i][j]=a[j][i]=ans[j][i]=0;
}

inline int calc(){
    int res=0;
    for(register int p=1;p<=2;++p){
        for(register int i=2;i<=m;++i)
            if(!ans[1][i])
                ans[1][i]=ans[1][i-1];
        for(register int i=2;i<=n;++i)
            if(!ans[i][m])
                ans[i][m]=ans[i-1][m];
        for(register int i=m-1;i;--i)
            if(!ans[n][i])
                ans[n][i]=ans[n][i+1];
        for(register int i=n-1;i;--i)
            if(!ans[i][1])
                ans[i][1]=ans[i+1][1];
        if(!ans[1][1])
            ans[1][1]=2;
    }
    for(register int i=2;i<=m;++i)
        if(ans[1][i]!=ans[1][i-1])
            ++res;
    for(register int i=2;i<=n;++i)
        if(ans[i][m]!=ans[i-1][m])
            ++res;
    for(register int i=m-1;i;--i)
        if(ans[n][i]!=ans[n][i+1])
            ++res;
    for(register int i=n-1;i;--i)
        if(ans[i][1]!=ans[i+1][1])
            ++res;
    return res;
}

inline bool Nice(){
    bool ok=0;
    for(register int i=1;i<=n;++i){
        if(ans[i][1]!=ans[1][1])
            return 0;
        if(i>1 && i<n && ans[i][m]!=ans[1][1])
            ok=1;
    }
    return ok;
}

int Red,Blue;

inline void findroad(int x,int y){
    if(ans[x-1][y]==Red || ans[x+1][y]==Red || ans[x][y+1]==Red) return;
    int X1=(x==2?1:n);
    if(y<=m-2 && ans[X1][y+2]==Red){
        ans[X1][y]=ans[X1][y+1]=Red;
        return;
    }
    int X2=(x==2?2:n-1);
    if(y<=m-2 && ans[X2][y+2]==Red){
        ans[X2][y+1]=Red;
        return;
    }
    int X3=(x==2?3:n-2),X4=(x==2?4:n-3);
    if(a[X4][y]!=Blue){
        ans[X3][y]=Red;
        return;
    }
    int Y=(y<=m-2?y+1:y-1);
    ans[X2][Y]=ans[X3][Y]=Red;
}

inline void bigroad(int x){
    for(register int j=2;j<=4;++j){
        bool ok=1;
        for(register int i=x-1;i<=x+2;++i)
            if(a[i][j]==Blue){
                ok=0;
                break;
            }
        if(ok){
            ans[x][j]=ans[x+1][j]=Red;
            return;
        }
    }
    for(register int i=x-1;i<=x+2;++i)
        if(!a[i][3])
            ans[i][3]=Red;
    if(a[x-1][3]){
        ans[x-1][2]=Blue,
        ans[x][4]=Red;
    }
    if(a[x+2][3]){
        ans[x+2][2]=Blue,
        ans[x+1][4]=Red;
    }
    if(a[x][3] || a[x+1][3]){
        ans[x][2]=ans[x+1][2]=Red;
    }
}

inline void buildroad(){
    int fr=0,ls=0;
    for(register int i=1;i<=n;++i)
        if(ans[i][m]==Red){
            if(!fr) fr=i;
            ls=i;
        }
    if(!fr || (ls>3 && fr<n-2)) return;
    if(ls<=3 && a[4][m-1]==Blue){
        ans[3][m]=ans[4][m]=ans[5][m]=Red;
        return;
    }
    if(fr>=n-2 && a[n-3][m-1]==Blue){
        ans[n-4][m]=ans[n-3][m]=ans[n-2][m]=Red;
        return;
    }
    int x=(ls<=3?2:n-2);
    for(register int i=x;i<=x+1;++i)
        for(register int j=m-1;j<=m;++j)
            if(!a[i][j])
                ans[i][j]=Red;
}

bool End;
#define File ""
signed main(){
    // #ifndef ONLINE_JUDGE
    // freopen(File ".in","r",stdin);
    // freopen(File ".out","w",stdout);
    // #endif
    for(register int T=read();T;--T,clear()){
        n=read(),m=read();
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
                a[i][j]=ans[i][j]=reads();
        int tmp=calc();
        if(tmp>=4){
            puts("NO");
            continue;
        }
        if(tmp>0) while(!Nice()) rotate();
        Blue=ans[1][1],Red=Blue^1;
        for(register int i=2;i<n;++i)
            for(register int j=2;j<m;++j)
                if(!a[i][j])
                    ans[i][j]=(i%4>1?Blue:Red);
        for(register int i=1;i<n;++i)
            if(ans[i][m-1]==ans[i+1][m] && ans[i+1][m-1]==ans[i][m] && ans[i][m]!=ans[i+1][m]){
                if(!a[i][m]) ans[i][m]^=1;
                else ans[i+1][m]^=1;
            }
        buildroad();
        for(register int i=2;i<m;++i){
            if(a[2][i]==Red) findroad(2,i);
            if(a[n-1][i]==Red) findroad(n-1,i);
        }
        for(register int i=6;i<=n-6;i+=4)
            if(ans[i][m]==Blue || ans[i+1][m]==Blue)
                bigroad(i);
        while(cntr%4!=0) rotate();
        puts("YES");
        for(register int i=1;i<=n;++i){
            for(register int j=1;j<=m;++j)
                write(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
}