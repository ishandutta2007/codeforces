#include <bits/stdc++.h>
using namespace std;

char ch[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    cin>>ch;
    long long br1=0,br=0,n=strlen(ch),i;
    for(i=0;i<n-4;i++){
        if(ch[i]=='h' && ch[i+1]=='e' && ch[i+2]=='a' && ch[i+3]=='v' && ch[i+4]=='y')br1++;
        if(ch[i]=='m' && ch[i+1]=='e' && ch[i+2]=='t' && ch[i+3]=='a' && ch[i+4]=='l')br+=br1;
    }
    cout<<br;
    return 0;
}