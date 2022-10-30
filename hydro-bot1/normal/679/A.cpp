// Hydro submission #631f2fdd32ae6c3198c90ed3@1662988253946
#include<bits/stdc++.h>
using namespace std;
int p[20]={0,2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49},s;
int main()
{
    string str;
    for(int i=1;i<=19;i++)
    {
        printf("%d\n",p[i]);
        fflush(stdout);
        cin>>str;
        if(str=="yes") s++;
        if(s>1)
        {
            printf("composite\n");
            return 0;
        }
    }
    printf("prime\n");
    return 0;
}