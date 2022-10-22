#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, S[10100];
char p[10100], q[10100];
int D[10100], T[10100];
struct ST{
    int a, m;
}st[10100];
int top;
void Put(int a, int m){
    while(top && st[top].m>=m){
        a=min(a, st[top].a+2*st[top].m-2*m);
        top--;
    }
    if(top && st[top].a <= a)return;
    top++;
    st[top]={a,m};
}
void Do(char ch){
    int i;
    top = 0;
    T[0]=1e9;
    for(i=1;i<=n;i++){
        T[i]=1e9;
        Put(D[i-1] - S[i-1], S[i-1]);
        if(p[i]==ch){
            if(top && st[top].a<8e8) T[i] = st[top].a + S[i-1];
        }
    }
    for(i=0;i<=n;i++)D[i]=T[i];
}
int main(){
    int i, j;
    scanf("%s",p+1);
    scanf("%s",q+1);
    for(i=1;p[i];i++){
        S[i]=S[i-1];
        if(p[i]=='.')S[i]--;
        else S[i]++;
    }
    n=i-1;
    for(i=1;q[i];i++);
    m=i-1;
    for(i=0;i<=n;i++)D[i]=1e9;
    D[0]=0;
    for(i=1;i<=m;i++){
        Do(q[i]);
    }
    int res=1e9, Mn=1e9;
    for(i=n;i>=1;i--){
        Mn=min(Mn,S[i]);
        res=min(res,D[i] + S[n]-Mn*2+S[i]);
    }
    printf("%d\n",res);
}