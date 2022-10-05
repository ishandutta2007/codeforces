#include<stdio.h>
#include<algorithm>

using namespace std;

struct mindol{int str,a,b;bool operator<(const mindol &a)const{return str>a.str;}};

mindol s[623456];

int chk[804],cnt;

int main()
{
    int n,a,b,str;
    scanf("%d",&n);n*=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            scanf("%d",&str);
            s[cnt++]={str,i,j};
        }
    }
    std::sort(s,s+cnt);
    for(int i=0;i<cnt;i++){
        mindol cur=s[i];
        if(chk[cur.a]||chk[cur.b])continue;
        chk[cur.a]=cur.b;
        chk[cur.b]=cur.a;
    }
    for(int i=1;i<=n;i++)printf("%d ",chk[i]);
}