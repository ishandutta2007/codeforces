#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[100010];
map<string,int> M;
struct data
{
    string x;
    int y;
}a[100010];

bool check(int x,int y)
{
    if (x+4>y) return false;
    if (s[x]!=92) return false;
    if (s[x+1]!='c') return false;
    if (s[x+2]!='i') return false;
    if (s[x+3]!='t') return false;
    if (s[x+4]!='e') return false;
    return true;
}

bool cmp(data x,data y)
{
    return x.y<y.y;
}

bool check1(char *s)
{
    if (s[0]!=92) return false;
    if (s[1]!='b') return false;
    if (s[2]!='e') return false;
    if (s[3]!='g') return false;
    if (s[4]!='i') return false;
    return true;
}

bool check2(char *s)
{
    if (s[0]!=92) return false;
    if (s[1]!='e') return false;
    if (s[2]!='n') return false;
    if (s[3]!='d') return false;
    if (s[4]!='{') return false;
    return true;
}

int main()
{
    gets(s);int S=0;
    while(!check1(s))
    {
        n=strlen(s);
        for (int i=0;i<n-4;i++)
            if (check(i,n-1))
            {
                int x=i+6;string y;
                while(s[x]!='}') y+=s[x],x++;
                M[y]=++S;
            }
        gets(s);
    }
    gets(s);int T=0;
    while(!check2(s))
    {
        a[++T].x=s;
        n=strlen(s);
        if (n>0)
        {
            for (int i=0;i<n;i++)
                if (s[i]=='{')
                {
                    int x=i+1;string y;
                    while(s[x]!='}') y+=s[x],x++;
                    a[T].y=M[y];
                }
        }
        gets(s);
    }
    int flag=0;
    for (int i=1;i<=T;i++)
        if (a[i].y!=i) {flag=1;break;}
    if (!flag) puts("Correct");
    else{
        puts("Incorrect");
        sort(a+1,a+1+T,cmp);
        putchar(92);
        cout<<"begin{thebibliography}{99}"<<endl;
        for (int i=1;i<=T;i++)
            cout<<a[i].x<<endl;
        putchar(92);
        cout<<"end{thebibliography}"<<endl;
    }
    return 0;
}