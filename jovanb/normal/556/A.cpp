#include <bits/stdc++.h>

using namespace std;
char ch[500000];
int main() {
    int n,br1=0,br0=0,i;
    cin>>n>>ch;
    for(i=0;i<n;i++){
        if(ch[i]=='0')br0++;
        else br1++;
    }
    cout<<abs(br1-br0);
    return 0;
}