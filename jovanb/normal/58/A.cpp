#include <bits/stdc++.h>

using namespace std;
char str[1000];
int main()
{
    cin>>str;
    int k=strlen(str);
    int i,br=1;
    for(i=0;i<k;i++){
        if(str[i]=='h' && br==1)br++;
        else if(str[i]=='e' && br==2)br++;
        else if(str[i]=='l' && br==3)br++;
        else if(str[i]=='l' && br==4)br++;
        else if(str[i]=='o' && br==5){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}