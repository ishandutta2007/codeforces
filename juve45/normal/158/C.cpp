#include <iostream>
#include <cstring>
#define DMAX 200

using namespace std;
int n;
char s[DMAX], sol[51*DMAX], com[5];

void SolveCd()
{int k=0;
    char* p;
    cin>>s;

    if(s[0]=='/') while(sol[k]!=NULL) sol[k]=NULL, k++;//memset(sol, 0, DMAX*sizeof(sol));

    p=strtok(s, "/");
    while(p)
    {
 int a=strlen(sol)-1;
    if(strcmp(p, "..")==0)
    {
        while(sol[a]!='/' && a>0)
            sol[a]=NULL, a--;
            sol[a]=NULL;
    }
    else{ sol[a+1]='/';
    sol[a+2]=NULL;
    strcat(sol, p);
    }
    p=strtok(NULL, "/");
    }
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>com;
    if(strcmp(com,"pwd")==0)
        cout<<sol<<'/'<<'\n';
    if(strcmp(com,"cd")==0)
    SolveCd();
    }
    return 0;
}