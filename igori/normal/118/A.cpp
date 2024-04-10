#include <iostream>
#include <string>
using namespace std;

int main()
{
    string g;
    cin>>g;
    int s=g.size();
    for(int i=0; i<s; i++)
    {
        if((g[i]!='a')&&(g[i]!='o')&&(g[i]!='y')&&(g[i]!='u')&&(g[i]!='e')&&(g[i]!='i')&&(g[i]!='A')&&(g[i]!='O')&&(g[i]!='Y')&&(g[i]!='U')&&(g[i]!='E')&&(g[i]!='I'))
        {if((g[i]>='a')&&(g[i]<='z'))
            cout<<"."<<g[i];
        if((g[i]>='A')&&(g[i]<='Z'))
            cout<<"."<<(char)(g[i]-'A'+'a');
        }
    }
}