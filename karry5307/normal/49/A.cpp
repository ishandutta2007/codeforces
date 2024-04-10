#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
string s;
int main(){
    getline(cin,s);
    int last=s.length()-1;
    while(!isalpha(s[last]))last--;
    if(last==-1){                            //#1
        printf("NO\n");
        return 0;
    }
    if(isalpha(s[last])==2){              //#2
        char a=s[last];
        if(a=='a'||a=='e'||a=='o'||a=='i'||a=='u'||a=='y')
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    else if(isalpha(s[last])==1){
        char a=s[last];
        if(a=='A'||a=='E'||a=='O'||a=='I'||a=='U'||a=='Y')
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}