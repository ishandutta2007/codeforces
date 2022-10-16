#include <iostream>

using namespace std;

string s;

bool isVoc(char c)
{
if(c=='A')
return 1;
if(c=='E')
return 1;
if(c=='I')
return 1;
if(c=='O')
return 1;
if(c=='U')
return 1;
if(c=='Y')
return 1;
return 0;
}

int main()
{
    string t="A";
    cin>>s;
    t+=s;
    t+="A";
    int c=1;
    int cmax=1;
    for(int i=0;i<t.size();i++)
    {
        if(isVoc(t[i])) {
            if(cmax < c)
                cmax=c;
            c=1;
        }
        else c++;
    }
    cout<<cmax<<'\n';


    return 0;
}