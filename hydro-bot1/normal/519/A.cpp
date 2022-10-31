// Hydro submission #625505f617cd4d0a4176470e@1649739264097
#include<bits/stdc++.h>
using namespace std;
int sw,sb;
int main()
{
    char c;
    while(cin>>c)
    {
        switch(c)
        {
            case 'Q':sw+=9;break;
            case 'R':sw+=5;break;
            case 'B':sw+=3;break;
            case 'N':sw+=3;break;
            case 'P':sw+=1;break;
            case 'q':sb+=9;break;
            case 'r':sb+=5;break;
            case 'b':sb+=3;break;
            case 'n':sb+=3;break;
            case 'p':sb+=1;break;
        }
    }
    if(sw>sb) printf("White\n");
    else if(sw<sb) printf("Black\n");
    else printf("Draw\n");
    return 0;
}