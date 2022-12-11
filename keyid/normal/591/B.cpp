#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=200005;

char s[MAXN],d[26];
int t[26];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for (int i=0;i<26;i++) t[i]=i;
    for (char x[2],y[2];m--;)
    {
        scanf("%s%s",x,y);
        swap(t[x[0]-'a'],t[y[0]-'a']);
    }
    for (int i=0;i<26;i++) d[t[i]]=i+'a';
    for (int i=0;i<n;i++) printf("%c",d[s[i]-'a']);
    return 0;
}