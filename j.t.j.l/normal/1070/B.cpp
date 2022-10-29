#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned int ui;

ui fuck[4] = {255, 65280, 16711680, 4278190080u};
int N;
struct ip
{
    ui addr,len;
    int sign;
    void print()
    {
        printf("%u.",(addr & fuck[3]) >> 24);
        printf("%u.",(addr & fuck[2]) >> 16);
        printf("%u.",(addr & fuck[1]) >> 8);
        printf("%u/",(addr & fuck[0]));
        printf("%d\n",len);
    }
}p[200010];

char s[50];
int pp[50];
int cnt;
int ch[7000010][2];
int col[7000010],fa[7000010];

void ins(ip P)
{
    ui t = P.addr;
    for (int i=32;i>=1;i--)
    {
        pp[i] = t % 2;
        t /= 2;
    }
    int now = 1;
    for (int i=1;i<=P.len;i++)
    {
        if (!ch[now][pp[i]])
        {
            ch[now][pp[i]] = ++cnt;
            fa[cnt] = now;
        }
        now = ch[now][pp[i]];
    }
    if (col[now] == -P.sign)
    {
        puts("-1");
        exit(0);
    }
    col[now] = P.sign;
}

ip read()
{
    scanf("%s",s);
    int len = strlen(s);
    bool slash = false;
    for (int i=0;i<len;i++)slash |= (s[i] == '/');
    if (!slash)
    {
        s[len++] = '/';
        s[len++] = '3';
        s[len++] = '2';
        s[len++] = 0;
    }

    //printf("%s\n",s);
    char sig;
    ui a,b,c,d,x;
    sscanf(s,"%c%u.%u.%u.%u/%u\n",&sig,&a,&b,&c,&d,&x);
    //printf("%c %u %u %u %u %u\n",sig,a,b,c,d,x);
    return (ip){((a<<24)|(b<<16)|(c<<8)|d),x,(sig=='+'?1:-1)};
}

ip make(int x)
{
    int len = 0;
    int digit[40];
    ui addr = 0;
    for (int i=x;i!=1;i=fa[i])
    {
        if (i == ch[fa[i]][0])
            digit[++len] = 0;
        else
            digit[++len] = 1;
    }
    reverse(digit+1,digit+len+1);
    for (int i=1;i<=len;i++)addr = addr * 2u + digit[i];
    return (ip){addr << (32 - len),len,1};
}

int main()
{
    cnt = 1;
    scanf("%d",&N);
    for (int i=1;i<=N;i++)p[i] = read();
    for (int i=1;i<=N;i++)ins(p[i]);
    //for (int i=1;i<=cnt;i++)printf("%d %d %d\n",i,fa[i],col[i]);
    for (int i = 1; i <= cnt; i++)
        if (col[i] == -1){
            for (int j = i; j; j = fa[j])
                if (col[j] == 1){
                    return 0 * puts("-1");
                }
        }
    for (int i=1;i<=cnt;i++)
    if (col[i] == 1)
    {
        for (int j=i;j;j=fa[j])
        {
            if (col[j] == -1)
                return 0 * puts("-1");
            col[j] = 1;
        }

    }
    for (int i=1;i<=cnt;i++)
    if (col[i] == -1)
    {
        for (int j=i;fa[j]&&col[fa[j]]!=1;j=fa[j])
        {
            //printf("fuck %d %d\n",j,fa[j]);
            col[j] = 0;
            col[fa[j]] = -1;
        }
    }

    vector<ip>ans;
    for (int i=1;i<=cnt;i++)
    if (col[i] == -1) ans.push_back(make(i));
    printf("%d\n",ans.size());
    for (auto t:ans) t.print();
}