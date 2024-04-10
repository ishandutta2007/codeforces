#include <bits/stdc++.h>

using namespace std;
char ch[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,i,br=0;
    cin>>ch;
    n=strlen(ch);
    for(i=0;i<n;i++){
        if(ch[i]>='0' && ch[i]<='9'){
            if((ch[i]-48)%2==1)br++;
        }
        else if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u')br++;
    }
    cout<<br;
    return 0;
}