#include <iostream>
#include<cstring>
using namespace std;
char sir[105];
char sir2[210];
int lg;
int main()
{
    cin.getline(sir,104);
    lg = strlen(sir);
    int j = 0;
    for(int i = 0 ; i < lg; i++)
    {
        if(sir[i]>='A' && sir[i]<='Z')
        {
            sir[i]+=32;
        }
        if(sir[i]!='a' && sir[i]!='e' && sir[i]!='i'&& sir[i]!='o'&& sir[i]!='u' && sir[i]!='y')
        {
            sir2[j++] = '.';
            sir2[j++] = sir[i];
        }
    }
    cout<<sir2;
    return 0;
}