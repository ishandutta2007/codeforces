#include <bits/stdc++.h>
using namespace std;
char ch[5];
int main(){
    int n,x=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ch;
        if(ch[1]=='+')x++;
        else x--;
    }
    cout<<x;
    return 0;
}