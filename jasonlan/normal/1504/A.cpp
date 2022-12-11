#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
string s;
void proc(){
    cin>>s;
    bool flag=true;
    for(int i=0;i<s.length();++i)
        if(s[i]!='a'){
            flag=false;break;
        }
    if(flag){
        puts("NO");return;
    }
    puts("YES");
    for(int i=0;i<s.length();++i){
        if(s[s.length()-i-1]!='a'){
            for(int j=0;j<i;++j)
                cout<<s[j];
            cout<<'a';
            for(int j=i;j<s.length();++j)
                cout<<s[j];
            cout<<endl;
            break;
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--)
        proc();
    return 0;
}